#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

/*int main(){
    std::ios::sync_with_stdio(false);
    long long i,j,k,m,n,t,ans;
    long long a[1000010],l[1000010],r[1000010],s[1000010];
    cin>>n>>k;
    t=0;
    s[0]=0;
    for(i=1;i<=n;i++) {
        cin>>a[i];
        while(t>0&&a[s[t]]<a[i]) {
            r[s[t]]=i;
            t--;
        }
        l[i]=s[t];
        s[++t]=i;
    }
    while(t>0) {
        r[s[t]]=n+1;
        t--;
    }
    
    ans=0;
    for(i=1;i<=n;i++) {
        /*j=r[i]-i-1;
        m=i-l[i]-1;
        if (j<m) {
            j+=m;
            m=j-m;
            j-=m;
        }
        if (j+m-1>=k) {
            /*ans+=((m-1)/(k-1))*((m-1)/(k-1)*(k-1)+1+k)/2*a[i];
            ans+=((j-1)/(k-1)-(m-1)/(k-1))*m*a[i];
            ans+=((j+m-2)/(k-1)-(j-1)/(k-1))*(j+m-1-(j+m-2)/(k-1)*(k-1)-1+j+m-1-(j-1)/(k-1)*(k-1)-1)/2*a[i];*
            ans=(ans+(m/k)*(m/k*k+k)/2*a[i])%MOD;
            ans=(ans+(j/k-m/k)*(m+1)*a[i])%MOD;
            ans=(ans+((j+m+1)/k-j/k)*(j+m+1-(j+m+1)/k*k+j+m+1-j/k*k)/2*a[i])%MOD;
        }*

		int x=i-l[i]-1,y=r[i]-i-1,u,v,w;
		if(x>y)w=x,x=y,y=w;
		u=x/k,v=y/k,w=(x+y+1)/k;
		ans=(ans+(u*(u+1ll)/2*k+u+(v-u)*(x+1ll)-(v+w+1ll)*(w-v)/2*k+(x+y+1ll)*(w-v))%MOD*a[i])%MOD;
    }
    cout<<ans;
    return 0;
}*/
const int maxn=1000010;
int main(){
    int n,k,a[maxn],s[maxn],*t=s,l[maxn],r[maxn];
	scanf("%d%d",&n,&k);
	--k;*t=-1;
	for(int i=0;i<n;i++){
		scanf("%d",a+i);
		while(t>s&&a[*t]<a[i])r[*t--]=i;
		l[i]=*t;*++t=i;
	}
	while(t>s)r[*t--]=n;
	int sum=0;
	for(int i=0;i<n;i++){
		int x=i-l[i]-1,y=r[i]-i-1,u,v,w;
		if(x>y)w=x,x=y,y=w;
		u=x/k,v=y/k,w=(x+y)/k;
		sum=(sum+(u*(u+1ll)/2*k+u+(v-u)*(x+1ll)-(v+w+1ll)*(w-v)/2*k+(x+y+1ll)*(w-v))%MOD*a[i])%MOD;
	}
	printf("%d",sum);
}