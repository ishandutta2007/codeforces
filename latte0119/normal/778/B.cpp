#include<bits/stdc++.h>
using namespace std;

#define int long long

typedef pair<int,int>pint;
typedef vector<int>vint;
typedef vector<pint>vpint;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(v) (v).begin(),(v).end()
#define rep(i,n) for(int i=0;i<(n);i++)
#define reps(i,f,n) for(int i=(f);i<(n);i++)
#define each(it,v) for(__typeof((v).begin()) it=(v).begin();it!=(v).end();it++)
template<class T,class U>void chmin(T &t,U f){if(t>f)t=f;}
template<class T,class U>void chmax(T &t,U f){if(t<f)t=f;}

char foo[5555];
string in(){
    scanf("%s",foo);
    return foo;
}
int N,M;

string S[5555];
int C[5555][2];
int T[5555];

int val[5555];

signed main(){
    scanf("%lld%lld",&N,&M);

    map<string,int>id;
    id["?"]=N;
    rep(i,N){
        string s=in();
        in();
        id[s]=i;
        string x;
        x=in();
        if(isdigit(x[0])){
            S[i]=x;
            T[i]=-1;
        }
        else{
            string o=in();
            string y=in();
            if(o=="AND")T[i]=0;
            else if(o=="OR")T[i]=1;
            else T[i]=2;
            C[i][0]=id[x];
            C[i][1]=id[y];
        }
    }

    string Min(M,'0'),Max(M,'0');
    for(int i=0;i<M;i++){
        int cnt[2]={};
        rep(k,2){
            val[N]=k;
            for(int j=0;j<N;j++){
                if(T[j]==-1)val[j]=S[j][i]-'0';
                else{
                    int a=val[C[j][0]];
                    int b=val[C[j][1]];
                    if(T[j]==0)val[j]=a&b;
                    else if(T[j]==1)val[j]=a|b;
                    else val[j]=a^b;
                }
                cnt[k]+=val[j]==1;
            }
        }
        if(cnt[0]<cnt[1]){
            Min[i]='0';
            Max[i]='1';
        }
        else if(cnt[0]>cnt[1]){
            Min[i]='1';
            Max[i]='0';
        }
        else{
            Min[i]=Max[i]='0';
        }
    }

    cout<<Min<<endl;
    cout<<Max<<endl;
    return 0;
}