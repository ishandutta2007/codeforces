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
template<class T,class U>inline void chmin(T &t,U f){if(t>f)t=f;}
template<class T,class U>inline void chmax(T &t,U f){if(t<f)t=f;}

int N;
string S,T;

char hoge[1000010],piyo[1000010];

string solve(vint cnt){
    string A,B,C,D,E;

    rep(i,T[0]-'0'){
        A+=string(cnt[i],'0'+i);
    }
    A+=T;
    reps(i,T[0]-'0',10)A+=string(cnt[i],'0'+i);

    rep(i,T[0]-'0'+1){
        B+=string(cnt[i],'0'+i);
    }
    B+=T;
    reps(i,T[0]-'0'+1,10)B+=string(cnt[i],'0'+i);

    C=T;
    rep(i,10)C+=string(cnt[i],'0'+i);

    reps(i,1,10){
        if(cnt[i]){
            cnt[i]--;
            D=E='0'+i;
            break;
        }
    }

    rep(i,T[0]-'0')D+=string(cnt[i],'0'+i);
    D+=T;
    reps(i,T[0]-'0',10)D+=string(cnt[i],'0'+i);


    rep(i,T[0]-'0'+1)E+=string(cnt[i],'0'+i);
    E+=T;
    reps(i,T[0]-'0'+1,10)E+=string(cnt[i],'0'+i);

    string ret="";
    if(A[0]!='0'){
        if(ret==""||ret>A)ret=A;
    }
    if(B[0]!='0'){
        if(ret==""||ret>B)ret=B;
    }
    if(C[0]!='0'){
        if(ret==""||ret>C)ret=C;
    }
    if(D[0]!='0'){

        if(ret==""||ret>D)ret=D;
    }
    if(E[0]!='0'){
        if(ret==""||ret>E)ret=E;
    }
    return ret;
}

signed main(){
    scanf("%s%s",hoge,piyo);
    S=hoge;
    T=piyo;

    vint cnt(10);
    rep(i,S.size())cnt[S[i]-'0']++;
    rep(i,T.size())cnt[T[i]-'0']--;


    string ans;
    for(int i=max(1ll,(int)S.size()-10);i<=S.size();i++){
        stringstream ss;
        ss<<i;
        string t;ss>>t;
        vint _cnt=cnt;
        rep(j,t.size()){
            _cnt[t[j]-'0']--;
        }
        bool ok=true;
        rep(j,10)if(_cnt[j]<0)ok=false;
        if(*max_element(_cnt.begin()+1,_cnt.end())==0&&T[0]=='0'){
            if(_cnt[0]==0&&T=="0"){
                ans="0";
                break;
            }
            else{
                ok=false;
            }
        }
        if(accumulate(all(_cnt),0ll)+T.size()!=i)ok=false;
        if(!ok)continue;

        string tmp=solve(_cnt);
        if(ans==""||ans.size()>tmp.size())ans=tmp;
        else if(ans.size()==tmp.size()&&ans>tmp)ans=tmp;
    }

    printf("%s\n",ans.c_str());
    return 0;
}