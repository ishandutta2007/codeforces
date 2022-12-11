    #include<cstdio>
    #include<algorithm>
     
    using namespace std;
     
    int n;
    long long a[2000001],c[1000001];
    int b[11000001],p[10000001];
    long long cc(long long pp){
    	long long o=0;
    	for(int j=1;j<=n;j++)
    		if(a[j]<pp)o+=pp-a[j];
    		else o+=min(pp-a[j]%pp,a[j]%pp);
    	return o;
    }
    int main(){
    	srand(7124312);
    	for(int i=2;i<=11000000;i++){
    		if(!b[i])p[++p[0]]=i;
    		for(int j=1;p[j]*i<=11000000;j++){
    			b[p[j]*i]=1;
    			if(i%p[j]==0)break;
    		}
    	}
    	scanf("%d",&n);
    	for(int i=1;i<=n;i++)
    		scanf("%I64d",&a[i]);
    	long long ans=n;
    	for(int i=1;i<=50;i++)
    		ans=min(ans,cc(p[i]));
    	for(int tt=1;tt<=100;tt++){
    		int u=(rand()*32768ll+rand())%n+1;
    		for(int kk=-1;kk<=1;kk++){
    			long long o=a[u]+kk;
    			if(o==0)continue;
    			c[0]=0;
    			for(int i=1;1ll*p[i]*p[i]<=o;i++)
    				if(o%p[i]==0){
    					c[++c[0]]=p[i];
    					while(o%p[i]==0)
    						o/=p[i];
    				}
    			if(o!=1)c[++c[0]]=o;
    			for(int i=1;i<=c[0];i++)
    				if(c[i]>100)
    					ans=min(ans,cc(c[i]));
    		}
    	}
    	printf("%I64d\n",ans);
    }