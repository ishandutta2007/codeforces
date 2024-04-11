#include<bits/stdc++.h>
using namespace std;
const int N=55;
const int MOD=1e9+7;
const int INF=1e9+7;
inline int add(int a,int b){return (a+b)%MOD;}
inline int mul(int a,int b){return ((long long)a*(long long)b)%MOD;}
typedef pair<int,int> PII;
inline PII mg(PII a,PII b){
    if(a.first<b.first)return a;
    if(a.first>b.first)return b;
    return PII(a.first,add(a.second,b.second));
}
int c[N][N]={0};
int k;
int cnt[2];

bool done[N][N][2]={false};
PII ans[N][N][2];

struct State{
    int c0,c1,cw;
};

template<class T>
inline T &index(T arr[N][N][2],State x){
    return arr[x.c0][x.c1][x.cw];
}

int main(){
    int n;
    scanf("%d%d",&n,&k);
    c[0][0]=1;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=i;j++){
            c[i][j]=add(
                j>0?c[i-1][j-1]:0,
                j<i?c[i-1][j]:0
            );
        }
    }
    k/=50;
    for(int i=1;i<=n;i++){
        int w;
        scanf("%d",&w);
        cnt[w/50-1]++;
    }
    static queue<State> q;
    done[cnt[0]][cnt[1]][0]=true;
    ans[cnt[0]][cnt[1]][0]=PII(0,1);
    q.push((State){cnt[0],cnt[1],0});

    while(!q.empty()){
        State st=q.front();
        PII now=index(ans,st);
        q.pop();
        if(st.c0==0&&st.c1==0)break;
        if(st.cw==0){
            for(int i=0;i<=st.c0;i++){
                for(int j=0;j<=st.c1;j++){
                    if((i==0&&j==0)||i+2*j>k)continue;
                    PII sol(now.first+1,mul(now.second,mul(c[st.c0][i],c[st.c1][j])));
                    State newSt={st.c0-i,st.c1-j,1^st.cw};
                    if(!index(done,newSt)){
                        index(done,newSt)=true;
                        q.push(newSt);
                        index(ans,newSt)=PII(INF,0);
                    }
                    index(ans,newSt)=mg(index(ans,newSt),sol);
                }
            }
        }else{
            int p0=cnt[0]-st.c0,p1=cnt[1]-st.c1;
            for(int i=0;i<=p0;i++){
                for(int j=0;j<=p1;j++){
                    if((i==0&&j==0)||i+2*j>k)continue;
                    PII sol(now.first+1,mul(now.second,mul(c[p0][i],c[p1][j])));
                    State newSt={st.c0+i,st.c1+j,1^st.cw};
                    if(!index(done,newSt)){
                        index(done,newSt)=true;
                        q.push(newSt);
                        index(ans,newSt)=PII(INF,0);
                    }
                    index(ans,newSt)=mg(index(ans,newSt),sol);
                }
            }
        }
    }

    PII an=index(ans,(State){0,0,1});
    if(!index(done,(State){0,0,1}))an=PII(-1,0);
    cout<<an.first<<endl<<an.second<<endl;
    return 0;
}