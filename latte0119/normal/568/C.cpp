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

string latte="VC";
int foo(char c){
    return find(all(latte),c)-latte.begin();
}

vint L;
int N,M;
bool F[444][444];
string S;

char ma[2];
int luz[444];
vint G[444];
string ans;

string calc(int k){
    if(k==S.size())return "";

    assert(!(luz[k*2]&&luz[k*2+1]));

    int t;
    if(luz[k*2])t=0;
    else if(luz[k*2+1])t=1;
    else t=ma[1]>ma[0];

    for(auto u:G[2*k+t])luz[u]++;
    string res=calc(k+1);
    for(auto u:G[2*k+t])luz[u]--;
    res=string(1,ma[t])+res;
    return res;
}

signed main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    string l;
    cin>>l;
    L.resize(l.size());
    rep(i,L.size())L[i]=foo(l[i]);

    cin>>N>>M;
    rep(i,M){
        int a,b;
        char c,d;
        cin>>a>>c>>b>>d;
        a--;b--;
        int x,y;
        x=foo(c);
        y=foo(d);


        F[2*a+x][2*b+y]=1;
        F[2*b+1-y][2*a+1-x]=1;
    }

    cin>>S;

    rep(k,2*N)rep(i,2*N)rep(j,2*N)F[i][j]|=F[i][k]&F[k][j];

    rep(i,L.size()){
        if(L[i])ma[1]='a'+i;
        else ma[0]='a'+i;
    }


    rep(i,N){
        if(F[i*2][i*2+1])luz[i*2+1]=1;
        if(F[i*2+1][i*2])luz[i*2]=1;
        if(ma[0]==0)luz[i*2+1]=1;
        if(ma[1]==0)luz[i*2]=1;
    }

    while(true){
        bool update=false;
        rep(i,2*N){
            if(luz[i]==0)continue;
            rep(j,2*N){
                if(F[i][j]&&luz[j]==0){
                    update=true;
                    luz[j]=1;
                }
            }
        }
        if(!update)break;
    }

    rep(i,N)if(luz[i*2]&&luz[i*2+1]){
        cout<<-1<<endl;
        return 0;
    }

    rep(i,2*N)for(int j=i+1;j<2*N;j++)if(F[i][j])G[i].pb(j);

    bool izr=true;
    rep(i,N){
        string s[2];
        rep(j,2){
            if(luz[i*2+1-j])continue;
            luz[i*2+j]++;
            s[j]=calc(i);
            luz[i*2+j]--;
        }
        int t=L[S[i]-'a'];
        if(s[t].size()){
            string ss=ans+string(1,S[i])+s[t].substr(1,s[t].size()-1);
            if(izr&&ss>=S){
                ans+=S[i];
                for(auto u:G[i*2+t])luz[u]++;
                continue;
            }
        }

        char nex[2]={};
        rep(j,2){
            if(s[j].size()==0)continue;
            for(char c='a'+L.size()-1;c>='a';c--){
                if(L[c-'a']!=j)continue;
                if(izr&&c<=S[i])continue;
                nex[j]=c;
            }
        }

        izr=false;
        if(nex[0]==0&&nex[1]==0){
            cout<<-1<<endl;
            return 0;
        }
        if(nex[0]==0)t=1;
        else if(nex[1]==0)t=0;
        else t=nex[0]>nex[1];

        ans+=nex[t];
        for(auto u:G[i*2+t])luz[u]++;
    }

    cout<<ans<<endl;
    return 0;
}