#include<bits/stdc++.h>
using namespace std;

const int N =10e5 + 9;

//----------
using cd = complex<double>;
const long double PI = acos(-1);

void fft(vector<cd> &a,bool invert){
    if(a.size()==1) return;
    cd omegaLUL;
    if (invert){
        omegaLUL = exp(cd(0,2*PI/a.size()));
    }else{
        omegaLUL = exp(cd(0,-2*PI/a.size()));
    }
    vector<cd>eve(a.size()/2),odd(a.size()/2);
    for(int i=0;i<a.size();i++){
        if (i%2==0) eve[i/2] = a[i];
        else odd[i/2] = a[i];
    }
    fft(eve,invert);
    fft(odd,invert);
    cd w = {1,0};
    for(int i=0;i<a.size()/2;i++){
        a[i]=eve[i] + w*odd[i];
        a[a.size()/2+i]=eve[i] - w*odd[i];
        w*=omegaLUL;
    }
    if(invert) for(auto &i:a) i/=2;
} 

vector<long long> multiply(vector<long long>a,vector<long long>b){
    vector<cd> fa(a.begin(), a.end()), fb(b.begin(), b.end());
    int m = a.size() + b.size();
    int n = 1;
    while(n<m) n<<=1;
    fa.resize(n);
    fb.resize(n);
    fft(fa,false);
    fft(fb,false);
    for(int i=0;i<n;i++)
        fa[i]*=fb[i];
    fft(fa,true);
    vector<long long>ret(n);
    for(int i=0;i<n;i++) ret[i] = round(fa[i].real());
    return ret;
}
// ----------
long long ans[N];
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long n, x; cin >> n >> x;
  vector<long long> a(n + 1, 0), b(n + 1, 0), c(n + 1, 0);
  int nw = 0;
  a[0]++; b[n]++;
  long long z = 0;
  for (int i = 1; i <= n; i++) {
    int k; cin >> k;
    nw += k < x;
    a[nw]++; b[-nw + n]++;
    z += c[nw] + !nw; c[nw]++;
  }
  auto res = multiply(a, b);
  for (int i = n + 1; i < res.size(); i++) {
    ans[i - n] += res[i];
  }
  ans[0] = z;
  for (int i = 0; i <= n; i++) cout << ans[i] << ' ';
  cout << '\n';
  return 0;
}