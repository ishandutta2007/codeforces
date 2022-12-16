#include<iostream>
#include<cstdio>

using namespace std;

int y,m,d,a[3];
int od[6][3] = {
	{0, 1, 2},
	{0, 2, 1},
	{1, 0, 2},
	{1, 2, 0},
	{2, 0, 1},
	{2, 1, 0},
};

int mo[2][20] = {
	{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
	{0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
};
bool leap_year(int k){
	return k % 4 == 0;
}

bool check(int a,int b,int c){
	if(b > 12 || c > mo[leap_year(a)][b]) return 0;
	return y - a > 18 || (y - a == 18 && m > b) || (y - a == 18 && m == b && d >= c);
}

int main(){
	scanf("%d.%d.%d", &d, &m, &y);
	scanf("%d.%d.%d", &a[0], &a[1], &a[2]);
	
	for(int i = 0; i < 6; ++i)
		if(check(a[od[i][0]], a[od[i][1]], a[od[i][2]])) return printf("YES\n"), 0;
	printf("NO\n");
	
	return 0;
}
// CF30B