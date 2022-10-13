#include<stdio.h>
#include<set>
#include<utility>
#include<algorithm>
using namespace std;
int n,la;
set<int> ss;
pair<int,int> a[333];
bool intersect(pair<int,int> a,pair<int,int> b){
	return a.first <= b.second && b.first <= a.second;
}
int main(){
	scanf("%d",&n);
	ss.insert(1);
	for(int i=1; i<=n; i++){
		int s,e;
		scanf("%d%d",&s,&e);
		pair<int,int> v = make_pair(s,s+e-1);
		bool ff = true;
		for(int j=1; j<i; j++)
			if(intersect(a[j],v)){
				ff = false;
				break;
			}
		if(ff){
			printf("%d %d\n",v.first,v.second);
			a[i] = v;
			ss.insert(v.second+1);
		}else{
			for(set<int>::iterator it=ss.begin(); it!=ss.end(); it++){
				v=make_pair(*it,*it+e-1);
				bool ff = true;
				for(int j=1; j<i; j++)
					if(intersect(a[j],v)){
						ff = false;
						break;
					}
				if(ff){
					printf("%d %d\n",v.first,v.second);
					a[i] = v;
					ss.insert(v.second+1);
					break;
				}
			}
		}
	}
	return 0;
}