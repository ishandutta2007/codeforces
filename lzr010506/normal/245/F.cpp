#include <bits/stdc++.h>
using namespace std;
char ch[10000010];
int n, m, s[20010], day[13]={0, 0, 31, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335};

int Turn(char *a)
{
	int sum = 0;
	sum += day[(a[5] - '0') * 10 + a[6] - '0'];
	sum += (a[8] - '0') * 10 + a[9] - '0';
	sum *= 3600 * 24;
	sum += 3600 * ((a[11] - '0') * 10 + a[12] - '0');
	sum += 60 * ((a[14] - '0') * 10 + a[15] - '0');
	sum += 10 * (a[17] - '0') + a[18] - '0';
	return sum;
}

int main()
{
	bool flag = 0;
	int X = 0, Y = 0;
	scanf("%d%d\n", &n, &m);
	while(gets(ch) != NULL)
	{
		Y ++;
		s[Y] = Turn(ch);
		while(s[Y] - s[X] >= n)
		X ++;
		if(Y - X + 1 >= m)
		{
			for(int i = 0; i <= 18; i ++) printf("%c", ch[i]);
			flag = 1;
			break;
		}	
	}
	if(!flag) printf("-1");
	return 0;
}