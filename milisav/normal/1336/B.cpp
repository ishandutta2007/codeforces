#include<bits/stdc++.h>
using namespace std;
set<int> s[3];
set<int>::iterator it,jt;
int main() {
	int t;
	scanf("%d",&t);
	while(t--) {
		//cout<<t<<endl;
		s[0].clear();
		s[1].clear();
		s[2].clear();
		int n,m,k;
		scanf("%d %d %d",&n,&m,&k);
		//cout<<" "<<n<<" "<<m<<" "<<k<<endl;
		for(int i=0;i<n;i++) {
			int w;
			scanf("%d",&w);
			s[0].insert(w);
		}
		for(int i=0;i<m;i++) {
			int w;
			scanf("%d",&w);
			s[1].insert(w);
		}
		for(int i=0;i<k;i++) {
			int w;
			scanf("%d",&w);
			s[2].insert(w);
		}
		//cout<<"ok"<<endl;
		long long ans=-1;
		for(int i=0;i<3;i++) {
			for(int j=0;j<3;j++) {
				if(i==j) continue;
				for(int k=0;k<3;k++) {
					if(k==i || k==j) continue;
					for(auto p:s[i]) {
						it=s[j].lower_bound(p);
						if(it!=s[j].end()) {
							int q=(*it);
							//cout<<p<<" "<<q<<endl;
							int f=(p+q)/2;
							jt=s[k].lower_bound(f);
							if(jt!=s[k].end()) {
								int r=(*jt);
								long long a=p-q;
								long long b=p-r;
								long long c=q-r;
								long long ca=a*a+b*b+c*c;
								if(ans==-1 || ca<ans) ans=ca;
							}
							if(jt!=s[k].begin()) {
								jt--;
								int r=(*jt);
								long long a=p-q;
								long long b=p-r;
								long long c=q-r;
								long long ca=a*a+b*b+c*c;
								if(ans==-1 || ca<ans) ans=ca;
							}
						}
						if(it!=s[j].begin()) {
							it--;
							int q=(*it);
							int f=(p+q)/2;
							jt=s[k].lower_bound(f);
							if(jt!=s[k].end()) {
								int r=(*jt);
								long long a=p-q;
								long long b=p-r;
								long long c=q-r;
								long long ca=a*a+b*b+c*c;
								if(ans==-1 || ca<ans) ans=ca;
							}
							if(jt!=s[k].begin()) {
								jt--;
								int r=(*jt);
								long long a=p-q;
								long long b=p-r;
								long long c=q-r;
								long long ca=a*a+b*b+c*c;
								if(ans==-1 || ca<ans) ans=ca;
							}
						}
					}
				}
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}