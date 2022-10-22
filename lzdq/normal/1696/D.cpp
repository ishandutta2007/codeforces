#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
typedef long long ll;
const int MAXN=2.5e5+5;
int n,a[MAXN],f[MAXN];
vector<int> s1,s2;
int main(){
	//freopen("in1.txt","r",stdin);
	int _; scanf("%d",&_);
	while(_--){
		scanf("%d",&n);
		for(int i=1; i<=n; i++)
			scanf("%d",a+i);
		s1.clear();
		s2.clear();
		s1.push_back(1);
		s2.push_back(1);
		f[1]=0;
		for(int i=2; i<=n; i++){
			while(!s1.empty()&&a[s1.back()]<a[i]) s1.pop_back();
			while(!s2.empty()&&a[s2.back()]>a[i]) s2.pop_back();
			f[i]=n+1;
			if(!s1.empty()){
				if(s2.empty()){
					f[i]=f[s1.front()];
				}else if(s2.back()<s1.back()){
					f[i]=f[s1[upper_bound(s1.begin(),s1.end(),s2.back())-s1.begin()]];
				}
			}
			if(!s2.empty()){
				if(s1.empty()){
					f[i]=f[s2.front()];
				}else if(s1.back()<s2.back()){
					f[i]=f[s2[upper_bound(s2.begin(),s2.end(),s1.back())-s2.begin()]];
				}
			}
			s1.push_back(i);
			s2.push_back(i);
			f[i]++;
		}
		printf("%d\n",f[n]);
	}
	return 0;
}