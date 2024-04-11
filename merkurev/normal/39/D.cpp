#include <iostream>

using namespace std;

int a[5], b[5];

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int i;
	for (i = 0;i < 3;i++)
		scanf("%d", &a[i]);
	for (i = 0;i < 3;i++)
		scanf("%d", &b[i]);
	for (i = 0;i < 3;i++){
		if (a[i] == b[i]){
			printf("YES");
			return 0;
		}
	}
	printf("NO");
	return 0;
}