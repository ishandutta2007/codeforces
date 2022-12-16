#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=100100;
int n;
pair<int,int> d[N];
vector<int> link;
vector<int> ol;
void ae(int u,int v){
	printf("%d %d\n",u,v);
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&d[i].first);
		d[i].second=i;
	}
	sort(d+1,d+n+1);
	reverse(d+1,d+n+1);
	for(int i=1;i<=n;i++){
		int x=d[i].second*2-1;
		if(!link.empty()){
			ae(x,link.back());
		}
		link.push_back(x);
	}
	ol=link;
	int cl=n;
	for(int i=1;i<=n;i++){
		int x=d[i].second*2;
		if(i>cl){
			ae(x,ol[i-d[i].first]);
			continue;
		}
		while((int)link.size()-i>d[i].first-1){
			link.pop_back();
			cl=min(cl,(int)link.size());
		}
		ae(x,link.back());
		link.push_back(x);
	}
	return 0;
}