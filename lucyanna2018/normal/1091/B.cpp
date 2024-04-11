#include<bits/stdc++.h>
using namespace std;
#define ran 1010
set<pair<int,int> > s;
int n,x[ran],y[ran],a[ran],b[ran];
int main(){
	scanf("%d",&n);
	for(int i=0; i<n; i++){
		scanf("%d%d",&x[i],&y[i]);
		s.insert(make_pair(x[i], y[i]));
	}
	for(int i=0; i<n; i++)
		scanf("%d%d",&a[i],&b[i]);
	for(int t=0; t<n; t++){
		int X = a[0] + x[t], Y = b[0] + y[t];
		bool flag = true;
		for(int i=0; i<n; i++){
			if(!s.count(make_pair(X-a[i], Y-b[i]))){
				flag = false;
				break;
			}
		}
		if(flag){
			printf("%d %d\n",X,Y);
			return 0;
		}
	}
	return 0;
}