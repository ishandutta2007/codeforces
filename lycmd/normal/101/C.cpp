#include<bits/stdc++.h>
#define int long long
using namespace std;
int ax,ay,bx,by,cx,cy;
void rotate(int&x,int&y,int k){
	swap(x,y),y*=-1;
	if(k)rotate(x,y,k-1);
}
signed main(){
	cin>>ax>>ay>>bx>>by>>cx>>cy;
	int flg=0;
	for(int i=0;i<4;i++){
		int tax=ax,tay=ay,tcx=cx,tcy=cy;
		rotate(ax,ay,i);
		flg|=cx||cy?(bx*cy-by*cx-ax*cy+ay*cx)%(cx*cx+cy*cy)==0&&
			(bx*cx+by*cy-ax*cx-ay*cy)%(cx*cx+cy*cy)==0:ax==bx&&ay==by;
		ax=tax,ay=tay,cx=tcx,cy=tcy;
	}
	cout<<(flg?"YES\n":"NO\n");
}