#include <bits/stdc++.h>
using namespace std;
int n;
int A_num, C_num, G_num, T_num;
char ch[500];
int main()
{
	scanf("%d", &n);
	if(n % 4 != 0) {cout << "==="; return 0;}
	scanf("%s", ch);
	for(int i = 0; i < n; i ++)
		if(ch[i] == 'A') A_num ++;
		else if(ch[i] == 'C') C_num ++;
		else if(ch[i] == 'G') G_num ++;
		else if(ch[i] == 'T') T_num ++;
	int x = n / 4;
	if(A_num > x || C_num > x || G_num > x || T_num > x) {cout << "==="; return 0;}
	for(int i = 0; i < n; i ++)
		if(ch[i] == '?')
		{
			if(A_num < x) ch[i] = 'A', A_num ++;
			else if(C_num < x) ch[i] = 'C', C_num ++;
			else if(G_num < x) ch[i] = 'G', G_num ++;
			else if(T_num < x) ch[i] = 'T', T_num ++;
		}
	printf("%s", ch);
	return 0;
}