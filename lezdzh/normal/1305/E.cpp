    #include<cstdio>
     
    using namespace std;
     
    int a[10001];
    int main(){
    	int n,m;
    	scanf("%d%d",&n,&m);
    	int o=0;
    	for(int i=1;i<=n;i++){
    		if(o+(i-1)/2>m){
    			a[a[0]+1]=a[a[0]]+(o+(i-1)/2-m)*2+1;
    			a[0]++;
    			for(int j=i+1;j<=n;j++)
    				a[++a[0]]=1e8+j*10000+1;
    			o=m;
    			break;
    		}
    		else{
    			a[a[0]+1]=a[a[0]]+1;
    			a[0]++;
    			o+=(i-1)/2;
    		}
    	}
    	if(o!=m){printf("-1");return 0;}
    	for(int i=1;i<=n;i++)
    		printf("%d%c",a[i],i==n?'\n':' ');
    }