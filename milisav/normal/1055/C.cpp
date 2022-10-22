#include<bits/stdc++.h>
using namespace std;
int la,lb,ra,rb,ta,tb;
int euclid(int x,int y) {
	if(x<y) swap(x,y);
	if(y==0) return x;
	else return euclid(y,x%y);
}
int main()
{
	scanf("%d %d %d",&la,&ra,&ta);
	scanf("%d %d %d",&lb,&rb,&tb);
	int d=euclid(ta,tb);
	int c1,c2;
	int c;
	c1=-1;
	c2=-1;
	if(lb<la) {
		swap(la,lb);
		swap(ra,rb);
	}
	int x=(lb-la)/d;
	if(x*d<lb-la) x++;
	//cout<<x<<endl;
	c1=max(-1,rb-la-x*d);
	if(rb<ra) {
		swap(la,lb);
		swap(ra,rb);
	}
	x=(rb-ra)/d;
	c2=max(-1,x*d+ra-lb);
	c=min(min(rb-lb,ra-la),max(c1,c2))+1;
	printf("%d\n",c);
	return 0;
}