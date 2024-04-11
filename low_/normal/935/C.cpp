#include<iostream>
#include<vector>
#include<queue>
#include<deque>
#include<algorithm>
#include<cmath>
#include<set>
#include<map>
#include<cstdio>
using namespace std;
#define int long long
#define inf 9223372036854775799
#define mn 100005

main()
{
//	freopen("test.inp", "r", stdin);
//	freopen("test.out", "w", stdout);
	
	int R, X1, X2, Y1, Y2;
	double Xap, Yap, r;
	cin>>R>>X1>>Y1>>X2>>Y2;
	
	int tx2=X2-X1, ty2=Y2-Y1;
	if (tx2*tx2+ty2*ty2>=R*R) cout<<X1<<" "<<Y1<<" "<<R;
	else if (X2==X1 && Y2==Y1)
    {
        Xap=(double)R/(double)2+X1;
        Yap=Y1;
        r=(double)R/(double)2;
        printf("%0.9f %0.9f %0.9f", Xap, Yap, r);
    }
    else
	{
		
		
		double x=(double)sqrt(((double)(R*R)/(double)(ty2*ty2+tx2*tx2))*tx2*tx2);
		double y;
		
		if (tx2==0) y=(double)sqrt(((double)(R*R)/(double)(ty2*ty2+tx2*tx2))*ty2*ty2);
		else y=((double)ty2/(double)tx2)*x;
		
		if (tx2>0 || (tx2==0 && ty2>0))
		{
			x=-x;
			y=-y;
		}
		
		Xap=(double)(tx2+x)/(double)(2)+X1;
		Yap=(double)(ty2+y)/(double)(2)+Y1;
		r=(double)sqrt((Xap-X2)*(Xap-X2)+(Yap-Y2)*(Yap-Y2));
		
		printf("%0.9f %0.9f %0.9f", Xap, Yap, r);
	}
}