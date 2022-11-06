#include<cstdio>
struct sur
{
	int c1,c2,c3,c4;
	inline bool colsame()
	{
		return c1==c3&&c2==c4&&c1!=c2;
	}
	inline bool same()
	{
		return c1==c2&&c2==c3&&c3==c4;
	}
	inline void right_rotate()
	{
		int t=c4;
		c4=c2;c2=c1;c1=c3;
		c3=t;
		return;
	}
	inline void left_rotate()
	{
		int t=c4;
		c4=c3;c3=c1;c1=c2;
		c2=t;
		return;
	}
	inline void rotate()
	{
		int t=c1;
		c1=c4;c4=t;
		t=c2;c2=c3;c3=t;
		return;
	}
	inline void read()
	{
		scanf("%d%d%d%d",&c1,&c2,&c3,&c4);
		return;
	}
	friend inline bool round(sur s1,sur s2,sur s3,sur s4)
	{
		if(!(s1.colsame()&&s2.colsame()&&s3.colsame()&&s4.colsame()))
			return 0;
		if(s1.c1==s2.c2&&s2.c1==s3.c2&&s3.c1==s4.c2&&s4.c1==s1.c2)
			return 1;
		if(s1.c2==s2.c1&&s2.c2==s3.c1&&s3.c2==s4.c1&&s4.c2==s1.c1)
			return 1;
		return 0;
	}
}code[7];
template<class Tp>
inline void swap(Tp &a,Tp &b)
{
	Tp t=a;
	a=b;b=t;
	return;
}
int main()
{
	int i;
	for(i=1;i<=6;i++)
		code[i].read();
	if(code[4].same()&&code[5].same())
	{
		code[6].rotate();
		puts(round(code[1],code[2],code[3],code[6])?"YES":"NO");
	}
	else if(code[1].same()&&code[3].same())
	{
		code[4].right_rotate();
		code[2].right_rotate();
		code[5].right_rotate();
		code[6].right_rotate();
		puts(round(code[4],code[2],code[5],code[6])?"YES":"NO");
	}
	else if(code[2].same()&&code[6].same())
	{
		code[1].right_rotate();
		code[3].left_rotate();
		code[4].rotate();
		puts(round(code[4],code[1],code[5],code[3])?"YES":"NO");
	}
	else
		puts("NO");
	return 0;
}