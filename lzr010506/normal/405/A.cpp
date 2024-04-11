#include <cstdio>
#include <algorithm>
using namespace std;
const int N=110;
int num[N];
int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",num+i);
	sort(num,num+n);
	for(int i=0;i<n;i++) printf("%d ",num[i]);
	return 0;
}