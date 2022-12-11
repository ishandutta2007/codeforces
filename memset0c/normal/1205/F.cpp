// luogu-judger-enable-o2
#include<bits/stdc++.h>
template<class T>inline void read(T &x){
    x=0;char c=getchar();bool f=0;
    while(!isdigit(c))f^=c=='-',c=getchar();
    while(isdigit(c))x=x*10+c-'0',c=getchar();
    if(f)x=-x;
}
const int N=110;
int T,n,k,lst,last,cnt,use,f[N][N*N],g[N][N*N];
std::vector<int> vet,ans,tmp,ano,pre[N];
std::vector<std::pair<int,int>> que;
void insert(int x,int opt){
    if(opt==1)ano=pre[x];
    else{
        last^=1,ano.clear();
        if(last)for(int i=1;i<=x;i++)ano.push_back(i);
        else for(int i=x;i>=1;i--)ano.push_back(i);
    }
    if(ans.size()){
        int cnt=0;for(int i=1;i<x;i++)cnt+=ano[i]<ano[0];
        for(int i=0;i<ans.size();i++)tmp.push_back(ans[i]+cnt);
        for(int i=1;i<ano.size();i++)tmp.push_back(ano[i]<ano[0]?ano[i]:ano[i]+ans.size()-1);
        ans=tmp,tmp.clear();
    }else ans=ano;
}
int main(){
#ifdef memset0
    freopen("1.in","r",stdin);
#endif
    f[1][0]=-1;
    for(int i=1;i<=100;i++){
        for(int j=0;j<=i*(i-1)/2;j++)
            for(int k=2;k<=i;k++){
                if(k>=4&&f[i-k+1][j-1])f[i][j]=1,g[i][j]=k;
                if(j-k*(k-1)/2>=0&&f[i-k+1][j-k*(k-1)/2])f[i][j]=2,g[i][j]=k;
            }
    }
    for(int k=4;k<=100;k++){
        vet.clear();for(int i=1;i<=k;i++)vet.push_back(i);
        while(true){
            std::random_shuffle(vet.begin(),vet.end());
            bool flag=false;
            for(int i=0;i<vet.size()&&!flag;i++)    
                for(int j=i+1;j<(i?vet.size():vet.size()-1);j++){                    int min=vet[j],max=vet[j];
                    for(int k=i;k<j;k++)min=std::min(min,vet[k]),max=std::max(max,vet[k]);
                    if(max-min==j-i){flag=true;break;}
                }
            if(!flag)break;
        }
        pre[k]=vet;     
    }
    for(vet.clear(),read(T);T--;vet.clear(),ans.clear(),que.clear(),cnt=use=0){
        read(n),read(k),lst=k-n,cnt=n;
        if(n==1&&k==1){puts("YES\n1");continue;}
        // printf("n=%d lst=%d f=%d\n",n,lst,f[n][lst]);
        if(lst<0||!f[n][lst]){puts("NO");continue;}
        for(int x=n,y=lst,k;~f[x][y];k=g[x][y],(f[x][y]==1?(x-=k-1,y-=1):(x-=k-1,y-=k*(k-1)/2))){
            // printf("> %d %d : %d %d\n",x,y,f[x][y],g[x][y]);
            que.push_back(std::make_pair(g[x][y],f[x][y]));
        }
        std::reverse(que.begin(),que.end());
        for(auto it=que.begin();it!=que.end();it++)insert(it->first,it->second);
        puts("YES");
        for(int i=0;i<n;i++)printf("%d%c",ans[i]," \n"[i==n-1]);
    }
}