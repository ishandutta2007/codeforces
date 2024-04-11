#include <bits/stdc++.h>

using namespace std;

#define PB push_back

const int maxn = 2e5 + 5;

class Point{
public:
  int x, y, id;
  inline Point(int x_ = 0, int y_ = 0, int id_ = 0): x(x_), y(y_), id(id_){}
  inline long long operator * (const Point &oth)const{ return 1ll * x * oth.y - 1ll * y * oth.x; }
  inline Point operator - (const Point &oth)const{ return Point(x - oth.x, y - oth.y); }
  inline bool operator < (const Point &oth)const{ return make_pair(x, y) < make_pair(oth.x, oth.y); }
} a[maxn], ext;

inline long double dis(Point p, Point q){ return sqrt(1ll * (p.x - q.x) * (p.x - q.x) + 1ll * (p.y - q.y) * (p.y - q.y)); }

int n, k;
long double pre[maxn], suf[maxn];
vector<Point> vec;

inline void fuck(){
  long double ans = 1e18;
  for(int i = 1; i < vec.size(); ++i)
    pre[i] = pre[i - 1] + dis(vec[i - 1], vec[i]);
  for(int i = (int)vec.size() - 2; i >= 0; --i)
    suf[i] = suf[i + 1] + dis(vec[i + 1], vec[i]);
  for(int i = 0; i < vec.size(); ++i){
    long double res = dis(ext, vec[i]);
    res += pre[i] + suf[i] + min(pre[i], suf[i]);
    ans = min(ans, res);
  }
  printf("%.10f\n", (double)ans);
  return;
}

inline long double solve(vector<Point> seq){
  for(int i = 1; i < seq.size(); ++i)
    pre[i] = pre[i - 1] + dis(seq[i - 1], seq[i]);
  for(int i = (int)seq.size() - 2; i >= 0; --i)
    suf[i] = suf[i + 1] + dis(seq[i + 1], seq[i]);
  long double ret = 1e18;
  for(int i = 0; i < seq.size(); ++i){
    long double res = dis(seq[i], ext) + dis(seq[i + 1], ext);
    res += pre[i] + suf[i + 1];
    ret = min(ret, res);
  }
  ret = min(ret, pre[seq.size() - 1] + dis(seq.back(), ext));
  return ret;
}

inline bool check(Point p, Point q){
  int cnt = 0;
  for(int i = 0; i < n; ++i)
    cnt += ((a[i] - p) * (a[i] - q) == 0);
  return (cnt == n - 1);
}

int main(){
  //freopen("G.in", "r", stdin);
  
  scanf("%d%d", &n, &k), --k;
  for(int i = 0; i < n; ++i)
    scanf("%d%d", &a[i].x, &a[i].y), a[i].id = i;
  Point p, q;
  if(check(a[0], a[1]))
    p = a[0], q = a[1];
  else if(check(a[0], a[2]))
    p = a[0], q = a[2];
  else
    p = a[1], q = a[2];
  
  for(int i = 0; i < n; ++i){
    if((a[i] - p) * (a[i] - q) == 0)
      vec.PB(a[i]);
    else
      ext = a[i];
  }
  sort(vec.begin(), vec.end());
  
  if(ext.id == k){
    fuck();
    return 0;
  }

  vector<Point> seq;
  int pos = -1;
  for(int i = 0; i < vec.size(); ++i)
    if(vec[i].id == k)
      pos = i;
  /*
  for(int i = 0; i < vec.size(); ++i)
    printf("%d (%d %d)\n", vec[i].id, vec[i].x, vec[i].y); puts("");
  */
  
  long double ans = 1e18;;
  for(int i = pos; i >= 0; --i)
    seq.PB(vec[i]);
  for(int i = pos + 1 ; i < vec.size(); ++i)
    seq.PB(vec[i]);
  ans = min(ans, solve(seq));
  seq.clear();
  for(int i = pos; i < vec.size(); ++i)
    seq.PB(vec[i]);
  for(int i = pos - 1; i >= 0; --i)
    seq.PB(vec[i]);
  ans = min(ans, solve(seq));
  printf("%.10f\n", (double)ans);
  return 0;
}