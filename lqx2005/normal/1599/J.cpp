#include<bits/stdc++.h>
using namespace std;
#define N 1005
int read(){
	int w=0,f=1;
	char c=' ';
	while(c<'0'||c>'9')c=getchar(),f=c=='-'?-1:f;
	while(c>='0'&&c<='9')w=w*10+c-48,c=getchar();
	return w*f;
}
int n,b[N],a[N],w[N];
vector<int>v[2];
signed main(){
	n=read();
	for(int i=1;i<=n;i++)
		b[i]=read();
	if(n==2){
		if(b[1]==b[2])return printf("YES\n%d 0\n",b[1]),0;
		else return puts("NO"),0;
	}
	for(int i=1;i<=n;i++)
		v[b[i]&1].push_back(i);
	if(v[0].size()==2&&v[1].size()==1){
		if(b[v[0][0]]!=b[v[0][1]])return puts("NO"),0;
		puts("YES");
		printf("%d %d %d\n",b[v[0][0]],b[v[1][0]],0);
		return 0;
	}
	if(v[0].size()>=3){
		a[n]=(b[v[0][0]]+b[v[0][1]]-b[v[0][2]])/2;
		for(int i=1,it=1;i<n;i++,it++){
			while(it==v[0][2])it++;
			a[i]=b[it]-a[n];
		}
		puts("YES");
		for(int i=1;i<=n;i++)
			printf("%d%c",a[i],i==n?'\n':' ');
		return 0;
	}
	if(v[1].size()>=2&&v[0].size()>=1){
		a[n]=(b[v[1][0]]+b[v[1][1]]-b[v[0][0]])/2;
		for(int i=1,it=1;i<n;i++,it++){
			while(it==v[0][0])it++;
			a[i]=b[it]-a[n];
		}
		puts("YES");
		for(int i=1;i<=n;i++)
			printf("%d%c",a[i],i==n?'\n':' ');
		return 0;
	}
	assert(((int)v[1].size())==n);
	sort(b+1,b+n+1,[&](int x,int y){return x>y;});
	for(int i=1;i<n;i++)
		if(b[i]==b[i+1]){
			a[n]=0;
			for(int j=1,k=0;j<=n;j++){
				if(j==i)continue;
				a[++k]=b[j];
			}
			puts("YES");
			for(int k=1;k<=n;k++)
				printf("%d%c",a[k],k==n?'\n':' ');
			return 0;
		}
//	for(int i=1;i<=n;i++)
//		for(int j=i+1;j<=n;j++){
//			auto tmp=p.insert({b[i]-b[j],{i,j}});
//			if(tmp.second)continue;
//			int ta,tb;
//			tie(ta,tb)=tmp.first->second;
//			if(i!=ta&&i!=tb&&j!=ta&&j!=tb){
//				a[n]=(b[i]+b[j])/2;
//				a[n-1]=b[i]-a[n];
//				a[n-2]=b[j]-a[n];
//				a[n-3]=(b[ta]+b[tb])/2;
//				for(int k=1,l=0;k<=n;k++)
//					if(k!=i&&k!=j&&k!=ta&&k!=tb)
//						a[++l]=b[k]-a[n];
//				puts("YES");
//				for(int k=1;k<=n;k++)
//					printf("%d%c",a[k],k==n?'\n':' ');
//				return 0;
//			}
//		}
	clock_t tim=clock();
	while((double)tim/CLOCKS_PER_SEC<0.8){
		random_shuffle(b+1,b+n+1);
		for(int i=1;i<=n;i++)
			w[i]=w[i-1]+b[i];
		for(int i=1;i<=n;i++){
			unordered_map<int,int>mp;
			for(int j=1;j+i-1<=n;j++){
				if(mp[w[j+i-1]-w[j-1]]){
					int cnt=0,tmp=mp[w[j+i-1]-w[j-1]];
					a[cnt=1]=0;
					for(int k=tmp,l=j;l<=j+i-1;k++,l++){
						a[cnt+1]=b[l]-a[cnt],cnt++;
						if(l!=j+i-1)a[cnt+1]=b[k]-a[cnt],cnt++;
					}
					for(int k=1;k<=n;k++)
						if(!(tmp<=k&&k<=tmp+i-1)&&!(j<=k&&k<=j+i-1))a[++cnt]=b[k];
					puts("YES");
					for(int k=1;k<=n;k++)
						printf("%d%c",a[k],k==n?'\n':' ');
					return 0;
				}
				mp[w[j+i-1]-w[j-1]]=j;
			}
		}
		tim=clock();
	}
	puts("NO");
	return 0;
}