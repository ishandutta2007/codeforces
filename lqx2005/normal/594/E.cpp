#pragma GCC optimize(3)
#pragma GCC target("avx,sse2,sse3,sse4,mmx")
#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
const int N = 5e6 + 10, M = 1e7 + 10;
const int B = 19491001;
int n, k;
string s;
int l[M], r[M], tot = 0;
ull fn[N], bk[N], pw[N];
string len1(string s) {
  string t = s;
  reverse(t.begin(), t.end());
  if(t < s) return t;
  return s;
}


void Lyndon(int n, int m) {
  l[0] = r[0] = -1;
  tot = 0;
  for(int i = 0, j, k; i < n;) {
    j = i, k = i + 1;
    for(;j < m && k < m && s[j % n] <= s[k % n];) {
      if(s[j % n] == s[k % n]) j++;
      else j = i;
      k++;
    }
    for(;i <= j;){
      l[++tot] = i,r[tot] = i + (k - j) - 1;
      i += k - j;
    }
  }
  return;
}

void initpre(string s) {
  pw[0] = 1;
  for(int i = 1; i <= n + 2; i++) pw[i] = pw[i - 1] * B;
  for(int i = 1; i <= n; i++) {
    int c = s[i];
    fn[i] = fn[i - 1] * B + c;
  }
  for(int i = n; i >= 1; i--) {
    int c = s[i];
    bk[i] = bk[i + 1] * B + c;
  }
  return;
}

ull up(int l, int r) {
  return bk[l] - bk[r + 1] * pw[r - l + 1];
}
ull down(int l, int r) {
  return fn[r] - fn[l - 1] * pw[r - l + 1];
}

ull Val(int p, int l) {
  if(l <= p) return up(p - l + 1, p);
  return up(1, p) * pw[l - p] + down(p + 1, l);
}

char val(int p, int l) {
  if(l <= p) return s[p - l + 1];
  return s[l];  
}

ull vAl(int p, int l) {
  if(l <= p) return down(1, l);
  return down(1, p) * pw[l - p] + up(n - (l - p) + 1, n);
}

 
char vaL(int p, int l) {
  if(l <= p) return s[l];
  return s[n - (l - p) + 1];
}
int cmp(int x, int y) {
  int l = 1, r = n, be = 0;
  int bf = min(n, 4);
  if(Val(x, bf) != Val(y, bf)) r = bf;
  while(l <= r) {
    int mid = (l + r) / 2;
    if(Val(x, mid) == Val(y, mid)) be = mid, l = mid + 1;
    else r = mid - 1;
  }
  return val(x, be + 1) < val(y, be + 1);
}

void midfind(string &mn) {
  int pos = 1;
  for(int i = 2; i <= n; i++) {
    if(s[i] <= s[pos] && cmp(i, pos)) {
      pos = i;
    }
  }
  string t = "";
  for(int i = pos; i >= 1; i--) t += s[i];
  for(int i = pos + 1; i <= n; i++) t += s[i];
  if(t < mn) mn = t;
  return;
}
int cmpf(int x, int y) {
  int l = min(x, y), r = n, be = l;
  int bf = min(n, l + 4);
  if(vAl(x, bf) != vAl(y, bf)) r = bf;
  while(l <= r) {
    int mid = (l + r) / 2;
    if(vAl(x, mid) == vAl(y, mid)) be = mid, l = mid + 1;
    else r = mid - 1;
  }
  return vaL(x, be + 1) < vaL(y, be + 1);
}


void frfind(string &mn) {
  int pos = 1;
  for(int i = 2; i <= n; i++) {
    if(cmpf(i, pos)) {
      pos = i;
    }
  }
  string t = "";
  // cout << pos << endl;
  for(int i = 1; i <= pos; i++) t += s[i];
  for(int i = n; i > pos; i--) t += s[i];
  if(mn > t) mn = t;
  return;
}

void mincir(string &mn) {
  reverse(s.begin(), s.end());
  Lyndon(n, n * 2);
  int pos = -1;
  for(int i = 1; i <= tot; i++) {
    if(l[i] < n) {
      pos = l[i];
    }
  }
  string in = "";
  for(int i = pos; i <= pos + n - 1; i++) in += s[i % n];
  // cout << in << endl;
  reverse(s.begin(), s.end());
  if(mn > in) mn = in;
  return;
}


string len2() {
  string mn = len1(s);
  n = (int)s.length();
  mincir(mn);
  s = '0' + s + '0';
  initpre(s);
  midfind(mn);
  frfind(mn);
  return mn;
}



void solve(string s, string &a, string &b, int k) {
  a.clear(), b.clear();
  int cnt = 0, i, fg = 0, n = s.length();
  int pl = -1, pr = -1;
  for(i = tot; i >= 1; i--) {
    if(l[i] == r[i]) {
      pl = pr = -1;
      if(!fg) {
        if(cnt >= k) break;
        cnt++, fg = 1;
      }
      continue;
    }
    if(pl != -1) {
      if(down(pl + 1, pr + 1) == down(l[i] + 1, r[i] + 1)) {
        // cout << pl <<" " << pr << endl;
        reverse(s.begin() + l[i], s.begin() + r[i] + 1);
        continue;
      }
    }
    if(cnt >= k) break;
    // cout << l[i] <<" " << r[i] << endl;
    cnt++;
    reverse(s.begin() + l[i], s.begin() + r[i] + 1);
    fg = 0;
    pl = l[i], pr = r[i];
  }
  for(int j = n - 1; j > r[i]; j--) a += s[j];
  for(int j = r[i]; j >= 0; j--) b += s[j];
  return;
}

string work() {
  string a, b, t = s;
  if(k == 1) {
    return len1(s);
  }
  n = s.length();
  t = '0' + s;
  initpre(t);
  solve(s, a, b, k);
  // cout << a << endl;
  if(b.empty()) return a;
  solve(s, a, b, k - 2);
  s = b;
  a += len2();
  return a;
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  // freopen("in.in", "r", stdin);
  cin >> s >> k;
  reverse(s.begin(), s.end());
  n = s.length();
  Lyndon(n, n);
  string ans = work();
  cout << ans << endl;
  return 0;
}