#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<functional>
#include<vector>
#include<queue>
using namespace std;
#define f(i,n) for(int i=0;i<(int)n;i++)
#define MOD 1000000009

int main(void){
	char a0[200] = "What are you doing at the end of the world? Are you busy? Will you save us?";
	char b1[100] = "What are you doing while sending Z";
	char b2[100] = "Z? Are you busy? Will you send Z";
	char b3[100] = "Z?";
	long long p[100001];
	int n;
	long long m;
	int q;
	p[0] = 75;
	for (int i = 1; i < 100001; i++){
		if (p[i - 1] == 1100000000000000000)p[i] = p[i - 1];
		else{
			p[i] = (p[i - 1] * 2) + 68;
			if (p[i] >= 1100000000000000000)p[i] = 1100000000000000000;
		}
	}

	scanf("%d", &q);

	f(qq, q){
		scanf("%d %I64d", &n, &m);
		if (p[n] < m)printf(".");
		else{
			m--;
			for (int i = n; i >= 0; i--){
				if (i == 0){
					if(a0[m]!='Z')printf("%c", a0[m]);
					else printf("\"");
					break;
				}
				else{
					if (m < 34){
						if (b1[m] != 'Z')printf("%c", b1[m]);
						else printf("\"");
						break;
					}
					else if (m < 34 + p[i - 1]){
						m -= 34;
					}
					else if (m < 66 + p[i - 1]){
						if (b2[m - p[i - 1] - 34] != 'Z')printf("%c", b2[m - p[i - 1] - 34]);
						else printf("\"");
						break;
					}
					else if (m < (2 * p[i - 1]) + 66){
						m -= (p[i - 1] + 66);
					}
					else {
						if (b3[m - (2*p[i - 1]) - 66] != 'Z')printf("%c", b3[m - (2*p[i - 1]) - 66]);
						else printf("\"");
						break;
					}
				}
			}
		}
	}

	return 0;
}