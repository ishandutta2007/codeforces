#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<queue>
#define ll long long
using namespace std;
const int maxn=1000000+1010;
int n,i,a[maxn],tot,l[maxn],tot1,xy0=-2147483646,xy1=-1;
bool book[maxn];
int main()
{
    cin>>n;
    for (i=1;i<=n;i++)
	{
	   cin>>a[i];
	   if (a[i]==0)l[++tot]=i;
	   if (a[i]<0){
	   	    tot1++;
	       if(xy0<a[i])xy0=a[i],xy1=i;
	   }
    }
    int m=n;
    if (n==1)return 0;
    if (tot1%2==1){
    	if(tot>=1)printf("1 %d %d\n",xy1,l[1]);
    	else {
		    printf("2 %d\n",xy1);
    	}
    	n--;
    	book[xy1]=1;
    	if(n==1)return 0;
    }
    for(i=1;i<tot;i++){
        printf("1 %d %d\n",l[i],l[i+1]);	
        book[l[i]]=1;
        n--;
        if(n<=1)return 0;
	}
    if(tot>=1){n--;book[l[tot]]=1;printf("2 %d\n",l[tot]);}
    if(n<=1)return 0;
	queue<int>q;
	for(i=1;i<=m;i++)if(!book[i])q.push(i);
	while(!q.empty()){
		if(n<=1)return 0;
	    int u=q.front();
		q.pop();
		n--;
		int x1=q.front();
		printf("1 %d %d\n",u,x1);
	}
	return 0;
}