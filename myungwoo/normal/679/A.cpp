#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()

int main()
{
	vector <int> arr;
	for (int i=2;i<101;i++){
		bool sw = 0;
		for (int j=2;j<i;j++) if (i%j == 0) sw = 1;
		if (sw) continue;
		arr.pb(i);
	}
	int cnt = 0;
	for (int i=0;i<16;i++){
		printf("%d\n", arr[i]); fflush(stdout);
		char buf[9] = {0,};
		scanf("%s", buf);
		if (!strcmp(buf, "yes")){
			if (++cnt > 1){ puts("composite"); return 0; }
		}
		if (arr[i]*arr[i] < 101){
			printf("%d\n", arr[i]*arr[i]); fflush(stdout);
			char buf[9] = {0,};
			scanf("%s", buf);
			if (!strcmp(buf, "yes")){
				if (++cnt > 1){ puts("composite"); return 0; }
			}
		}
	}
	puts("prime");
}