    #include<cstdio>
    #include<set>
    using namespace std;
     
    const int md=1000000007;
    int f[200002];
    set<int>a;
    int main(){
      f[0]=f[1]=1;
      for(int i=2;i<=200001;i++  )
        f[i]=(f[i-1] +f[i-2])%md;
      int n,p;
      scanf("%d%d",&n,&p);
      for(int i=1;i<=n;i++  ){
        int x;
        scanf("%d",&x);
        a.insert(x);
      }
      for(set<int>::iterator ii=a.begin();ii!=a.end();){
        int i=*ii,ok=0;
        for(int j=i;j;){
          if(j&1)j=j/2;
          else if((j&3)==0)j=j/4;
          else break;
          if(a.count(j))ok=1;
        }
    ii++;
    if(ok)a.erase(i);
      }
      int ans=0;
      for(set<int>::iterator ii=a.begin();ii!=a.end();ii++  ){
        int i=*ii;
        int lg=0;
        for(int w=i;w;w>>=1)
          lg++  ;
        ans=(ans +f[max(0,p-lg+ 2)]-1)%md;
      }
      printf("%d\n",ans);
    }