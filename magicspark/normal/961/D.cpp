/*
Though leaves are many , the root is one.
Through all the lying days of my youth
I swayed my leaves and flowers in the sun.
Now I may wither into the truth.
- William Butler Yeats
*/
//#pragma GCC optimize("Ofast,no-stack-protector")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
//#pragma GCC target("avx,tune=native")
#include<bits/stdc++.h>
#define int long long
#pragma comment("-Wl,--stack=1024000000")
//#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
//using namespace __gnu_pbds;
const int inf=0x3f3f3f3f;
const double eps=1e-6;
const int mod=1000000007;
typedef long long ll;
#ifndef LOCAL
#define cerr if(0)cout
#define eprintf(...) 0
#else
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#endif
inline string getstr(string &s,int l,int r){string ret="";for(int i=l;i<=r;i++)ret.push_back(s[i]);return ret;}
int modpow(int x,int y,int md=mod){int ret=1;do{if(y&1)ret=(ll)ret*x%md;x=(ll)x*x%md;}while(y>>=1);return ret;}
int n;
int x[100005],y[100005];
pair<int,int>p[100005];
signed main(){
    srand(time(0));
cin>>n;
for(int i=1;i<=n;i++){
cin>>p[i].first>>p[i].second;
}
for(int i=0;i<300;i++){
random_shuffle(p+1,p+n+1);
for(int i=1;i<=n;i++)x[i]=p[i].first,y[i]=p[i].second;
vector<pair<int,int> >vec;
for(int i=3;i<=n;i++){
if((y[i]-y[2])*(x[i]-x[1])==(y[i]-y[1])*(x[i]-x[2])){
//skip
}else{
vec.push_back(make_pair(x[i],y[i]));
}
}
bool can=1;
for(int i=2;i<vec.size();i++){
if((vec[i].second-vec[1].second)*(vec[i].first-vec[0].first)==(vec[i].second-vec[0].second)*(vec[i].first-vec[1].first)){
//skip
}else can=0;
}
if(can){
puts("YES");
return 0;
}
}
puts("NO");
return 0;
}