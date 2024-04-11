#include<bits/stdc++.h>
#define ff(i,a,b) for(int i=(a),_b=(b);i<=_b;i++)
#define pb push_back
#define mp make_pair
#define fi first
#define se second

typedef long long ll;
using namespace std;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef pair<ll,char> ic;
typedef pair<ic,int> p;

const int MAX=1e5+5,INF=1e9;

int c[26];
string s;
vector<p> v;
ll f[MAX];

int getRange(int pos)
{
    ll A=f[pos];char B=s[pos+1];
    //cerr<<A<<" "<<B<<" "<<pos<<" ";
    vector<p>::iterator l=lower_bound(v.begin(),v.end(),p(ic(A,B),0));
    vector<p>::iterator r=upper_bound(v.begin(),v.end(),p(ic(A,B),pos-1));//cerr<<r-l<<endl;
    return r-l;
}

void init(void)
{
    ff(i,0,25) cin>>c[i];
    cin>>s;
}

void process(void)
{
    ll curr=0,res=0;
    ff(i,0,(int)s.size()-1)
    {
        curr+=c[s[i]-'a'];f[i]=curr;
        v.pb(mp(mp(curr,s[i]),i));
    }
    sort(v.begin(),v.end());
    //ff(i,0,v.size()-1) cerr<<v[i].fi.fi<<" "<<v[i].fi.se<<" "<<v[i].se<<endl;cerr<<endl;
    ff(j,1,(int)s.size()-2) res+=getRange(j);
    ff(i,0,(int)s.size()-2) if(s[i]==s[i+1]) res++;
    cout<<res;
}

int main(void)
{
    init();
    process();
    return 0;
}