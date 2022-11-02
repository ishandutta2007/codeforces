//#ifdef _MONYURA_
#pragma comment(linker,"/STACK:256000000")
//#endif

#include <iostream>
#include <iomanip>
#include <cstdio>
#include <bitset>
#include <memory>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <list>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <stack>
#include <complex>
#include <wchar.h>
#include <wctype.h>
#include <cmath>
#include <queue>
#include <ctime>
#include <numeric>


using namespace std;

template<typename T> T mabs(const T &a){ return a<0?-a:a;}
#define rep(x,y,z) for(int x=(y),e##x=(z);x<e##x;x++)
#define SQR(x) ((x)*(x))
#define all(c) (c).begin(), (c).end()

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef unsigned int ui;	
typedef short int si;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const double PI = acos(-1.0);


void run()
{
	char A[500][500]={"111111101010101111100101001111111",
"100000100000000001010110001000001",
"101110100110110000011010001011101",
"101110101011001001111101001011101",
"101110101100011000111100101011101",
"100000101010101011010000101000001",
"111111101010101010101010101111111",
"000000001111101111100111100000000",
"100010111100100001011110111111001",
"110111001111111100100001000101100",
"011100111010000101000111010001010",
"011110000110001111110101100000011",
"111111111111111000111001001011000",
"111000010111010011010011010100100",
"101010100010110010110101010000010",
"101100000101010001111101000000000",
"000010100011001101000111101011010",
"101001001111101111000101010001110",
"101101111111000100100001110001000",
"000010011000100110000011010000010",
"001101101001101110010010011011000",
"011101011010001000111101010100110",
"111010100110011101001101000001110",
"110001010010101111000101111111000",
"001000111011100001010110111110000",
"000000001110010110100010100010110",
"111111101000101111000110101011010",
"100000100111010101111100100011011",
"101110101001010000101000111111000",
"101110100011010010010111111011010",
"101110100100011011110110101110000",
"100000100110011001111100111100000",
"111111101101000101001101110010001"};
	int x,y;
	cin>>x>>y;
	cout<<A[x][y]<<endl;

}





int main()
{
#ifdef _MONYURA_
	freopen("test.in","r",stdin);	
	freopen("test.out","w",stdout);
	time_t st=clock();
#else
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
#endif
	run();
#ifdef _MONYURA_
	printf( "=============\n");
	printf("Time: %.2lf sec\n",(clock()-st)/double(CLOCKS_PER_SEC));
#endif

	return 0;
}

/*
3
abcdefghABCDEFGH
3
abc
a
abAB
xyz
1
xyz
abacaba
6
a
aba
caba 
acaba
ba
bacb
*/