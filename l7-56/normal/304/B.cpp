#include<iostream>
#include<cstdio>

using namespace std;

int s[2][20] = {
	{0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365},
	{0, 31, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335, 366}
};
int y1,m1,d1,y2,m2,d2;

bool leap(int y){
	return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
}

int main(){
	scanf("%d:%d:%d", &y1, &m1, &d1);
	scanf("%d:%d:%d", &y2, &m2, &d2);
	
	if(y2 > y1 || (y2 == y1 && m2 > m1) || (y2 == y1 && m2 == m1 && d2 > d1))
		swap(y1, y2), swap(m1, m2), swap(d1, d2); 
	
	int sum;
	if(y1 == y2) sum = s[leap(y1)][m1 - 1] - s[leap(y2)][m2 - 1] + d1 - d2;
	else{
		sum = s[leap(y2)][12] - s[leap(y2)][m2 - 1] - d2 + s[leap(y1)][m1 - 1] + d1;
		for(int i = y2 + 1; i < y1; ++i)
			sum += s[leap(i)][12];
	}
	
	printf("%d", sum);
	
	return 0;
}