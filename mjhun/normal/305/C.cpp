#include <cstdio>
#include <iostream>
#include <map>
using namespace std;
map<int,short> p;
int main(){
	int n,a,m;
	scanf("%d",&n);
	while(n--){
		scanf("%d",&a);
		if(p[a]){
			p.erase(a);
			a++;
			while(p[a]){
				p.erase(a);
				a++;
			}
			p[a]=1;
		}
		else
			p[a]=1;
	}
	m=p.rbegin()->first+1-p.size();
	cout<<m<<endl;
	return 0;
}