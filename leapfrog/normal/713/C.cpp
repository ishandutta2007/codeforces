//
//
#include<bits/stdc++.h>
using namespace std;
int n,a,i=1,x;long long rs=0;priority_queue<int>q;
int main()
{
	for(scanf("%d",&n);n--;) {scanf("%d",&x),q.push(x-=++i);if(x<q.top()) rs+=q.top()-x,q.pop(),q.push(x);}
	return printf("%lld\n",rs),0;
}