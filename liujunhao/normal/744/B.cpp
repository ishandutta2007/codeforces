#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;
template<class T>
void Read(T &x){
	char c;
	bool f(0);
	while(c=getchar(),c!=EOF){
		if(c=='-')
			f=1;
		else if(c>='0'&&c<='9'){
			x=c-'0';
			while(c=getchar(),c>='0'&&c<='9')
				x=x*10+c-'0';
			ungetc(c,stdin);
			if(f)
				x=-x;
			return;
		}
	}
}
vector<int>ql,qr;
typedef pair<int,int>pii;
vector<pii>q,tmp;
int n,a[2000],ans[2000];
int main()
{
	Read(n);
	int i,k;
	for(i=1;i<=n;i++)
		ans[i]=2e9;
	q.push_back(pii(1,n));
	while(!q.empty()){
		ql.clear();
		qr.clear();
		for(auto j=q.begin();j<q.end();j++){
			int t=j->second-j->first+1;
			t=(t+1)/2;
			for(k=0;k<t;k++)
				ql.push_back(k+j->first);
			for(k=j->first+t;k<=j->second;k++)
				qr.push_back(k);
		}
		printf("%d\n",ql.size());
		for(auto j=ql.begin();j<ql.end();j++){
			printf("%d ",*j); 
		}
		puts("");
		fflush(stdout);
		for(k=1;k<=n;k++)
			Read(a[k]);
		for(auto j=q.begin();j<q.end();j++){
			int t=j->second-j->first+1;
			t=(t+1)/2;
			for(k=j->first+t;k<=j->second;k++)
				ans[k]=min(ans[k],a[k]);
		}
		printf("%d\n",qr.size());
		for(auto j=qr.begin();j<qr.end();j++){
			printf("%d ",*j); 
		}
		puts("");
		fflush(stdout);
		for(k=1;k<=n;k++)
			Read(a[k]);
		for(auto j=q.begin();j<q.end();j++){
			int t=j->second-j->first+1;
			t=(t+1)/2;
			for(k=0;k<t;k++)
				ans[k+j->first]=min(ans[k+j->first],a[k+j->first]);
		}
		tmp.clear();
		for(auto j=q.begin();j<q.end();j++){
			int t=j->second-j->first+1;
			t=(t+1)/2;
			if(t>1)
				tmp.push_back(pii(j->first,j->first+t-1));
			if(j->second-j->first+1-t>1)
				tmp.push_back(pii(j->first+t,j->second));
		}
		q=tmp;
	}
	printf("-1\n");
	for(i=1;i<=n;i++)
		printf("%d ",ans[i]);
	puts("");
	fflush(stdout);
}