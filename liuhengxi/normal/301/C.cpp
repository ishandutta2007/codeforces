#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
template<typename T>void readmain(T &x)
{
	bool neg=false;
	unsigned int c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
template<typename T>T& read(T &x){readmain(x);return x;}
template<typename T,typename ...Tr>void read(T &x,Tr&... r){readmain(x);read(r...);}
int main()
{
	puts("0" "??" "<>1");
	puts("1" "??" "<>2");
	puts("2" "??" "<>3");
	puts("3" "??" "<>4");
	puts("4" "??" "<>5");
	puts("5" "??" "<>6");
	puts("6" "??" "<>7");
	puts("7" "??" "<>8");
	puts("8" "??" "<>9");
	puts("9" "??" ">>" "??" "0");
	puts("" "??" "<>1");
	puts("?0>>0?");
	puts("?1>>1?");
	puts("?2>>2?");
	puts("?3>>3?");
	puts("?4>>4?");
	puts("?5>>5?");
	puts("?6>>6?");
	puts("?7>>7?");
	puts("?8>>8?");
	puts("?9>>9?");
	puts("?>>" "??" "");
	puts(">>?");
	return 0;
}