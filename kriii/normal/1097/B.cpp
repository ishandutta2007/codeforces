#include <stdio.h>
#include <bitset>
using namespace std;

bool t[360],f[360];

int main()
{
	t[0] = 1;
	int n; scanf ("%d",&n); while (n--){
		int x; scanf ("%d",&x);
		for (int i=0;i<360;i++) if (t[i]){
			f[(i+x)%360] = f[(i+360-x)%360] = 1;
		}
		for (int i=0;i<360;i++){
			t[i] = f[i];
			f[i] = 0;
		}
	}
	puts(t[0]?"YES":"NO");
	return 0;
}