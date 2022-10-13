#include<queue>
#include<cstdio>
using namespace std;
#define ran 1111111
int n;
long long int m;
long long int c[ran],w[ran],d[ran];
priority_queue<pair<long long int,int> > q;
bool f[ran];
int main(){
	scanf("%d%I64d",&n,&m);
	for(int i=0; i<n; i++){
		scanf("%I64d",&c[i]);
		d[i] = c[i] % 100;
		f[i] = false;
	}
	for(int i=0; i<n; i++)
		scanf("%I64d",&w[i]);
	while(!q.empty())q.pop();
	long long int res = 0;
	for(int i=0; i<n; i++){
		if(d[i] != 0){
			q.push(make_pair(-w[i] * (100 - d[i]),i));
		}
		m -= d[i];
		if(m < 0){
			m += 100;
			res -= q.top().first;
			f[q.top().second] = true;
			q.pop();
		}
	}
	printf("%I64d\n",res);
	for(int i=0; i<n; i++)
		if(!f[i])
			printf("%I64d %I64d\n",c[i]/100,c[i]%100);
		else
			printf("%I64d %I64d\n",c[i]/100+1,0);
	return 0;
}