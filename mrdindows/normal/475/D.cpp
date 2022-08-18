#include <bits/stdc++.h>
#define snd(a) scanf("%d",&(a))
#define snlld(a) scanf("%lld",&(a))
#define rep(i,n) for((i)=0;(i)<(n);(i)+=1)
#define reps(i,s,n) for((i)=(s);(i)<(n);(i)+=1)
#define tr(container,it) for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)
#define pb push_back
#define pf push_front
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
#define fill(a,v) memset((a),(v),sizeof(a))
#define sz size()
#define mp make_pair
#define mod  1000000007
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
template<class T> inline T poww(T b,T p){ll a=1;while(p){if(p&1){a=(a*b);}p>>=1;b=(b*b);}return a;}
template<class T> inline T poww2(T b,int p){T a=1;while(p){if(p&1){a=(a*b);}p>>=1;b=(b*b);}return a;}
template<class T> inline T modpoww(T b,T p,T mmod){ll a=1;while(p){if(p&1){a=(a*b)%mmod;}p>>=1;b=(b*b)%mmod;}return a%mmod;}
template<class T>  inline T gcd(T a,T b){ if(b>a)return gcd(b,a);return ((b==0)?a:gcd(b,a%b));}
template<class T> inline void scan(vector<T>& a,int n){T b;int i; rep(i,n){cin>>b;a.pb(b);}}
inline void scand(vector<int>& a,int n){int b;int i; rep(i,n){snd(b);a.pb(b);}}
#define pii pair<int,int>
#define vpii vector<pii >
#define vi vector<int>
#define vvi vector<vi >
#define vl vector<long long>
#define fr first
#define sd second

vector<map<int,ll> > mm(2);
map<int,ll> tmm;
int a[100000],ca=0,b[100000];
int main(){
    int n,i,j,k,q,p=0;
    snd(n);
    rep(i,n){
        snd(k);
        ca=0;
        tr(mm[p],it){
            mm[!p][gcd<int>(k,it->fr)]+=it->sd;
            tmm[gcd<int>(k,it->fr)]+=it->sd;
        }
        tmm[k]++;
        mm[!p][k]++;
        mm[p].clear();
        p=!p;

    }
    snd(q);
    while(q--){
        snd(k);
        cout<<tmm[k]<<"\n";
    }

}