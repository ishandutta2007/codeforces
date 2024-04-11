#include<bits/stdc++.h>
using namespace std;

#define int long long

#define rep(i,n) for(int i=0;i<(n);i++)
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define fi first
#define se second
typedef vector<int>vint;
typedef pair<int,int>pint;
typedef vector<pint>vpint;

template<typename A,typename B>inline void chmin(A &a,B b){if(a>b)a=b;}
template<typename A,typename B>inline void chmax(A &a,B b){if(a<b)a=b;}

vector<int>zalgorithm(string s){
    vector<int>a(s.size());
    a[0]=s.size();
    int i=1,j=0;
    while(i<s.size()){
        while(i+j<s.size()&&s[j]==s[i+j])j++;
        a[i]=j;
        if(j==0){i++;continue;}
        int k=1;
        while(i+k<s.size()&&k+a[k]<j)a[i+k]=a[k],k++;
        i+=k;j-=k;
    }
    return a;
}

string S,T;

signed main(){
    cin.tie();ios_base::sync_with_stdio(false);

    cin>>S>>T;

    int s0=count(all(S),'0');
    int s1=S.size()-s0;

    int t0=count(all(T),'0');
    int t1=T.size()-t0;

    if(s0<t0||s1<t1){
        cout<<S<<endl;
        return 0;
    }

    vint z=zalgorithm(T);
    int L=-1;
    for(int i=T.size()-1;i>0;i--)if(z[i]==T.size()-i){
        L=z[i];
    }

    if(L==-1){
        int tmp=1001001001;
        if(t0)chmin(tmp,s0/t0);
        if(t1)chmin(tmp,s1/t1);
        string ans;
        rep(i,tmp)ans+=T;
        rep(i,s0-tmp*t0)ans+="0";
        rep(i,s1-tmp*t1)ans+="1";
        cout<<ans<<endl;
        return 0;
    }

    string ans=T;
    s0-=t0;
    s1-=t1;


    int z0;
    int z1;

    z0=count(T.begin()+L,T.end(),'0');
    z1=T.size()-L-z0;


    int tmp=1001001001;
    if(z0!=0)chmin(tmp,s0/z0);
    if(z1!=0)chmin(tmp,s1/z1);


   rep(i,tmp)ans+=T.substr(L,T.size()-L);

    s0-=z0*tmp;
    s1-=z1*tmp;
    rep(i,s0)ans+="0";
    rep(i,s1)ans+="1";
    cout<<ans<<endl;
    return 0;
}