#include <stdio.h>
#include <string>
using namespace std;

char A[3][3],B[3][3];

int main()
{
	scanf ("%s",A[0]);
	scanf ("%s",A[1]);
	scanf ("%s",B[0]);
	scanf ("%s",B[1]);

	string a = A[0], b = B[0];
	a += A[1][1];
	a += A[1][0];
	b += B[1][1];
	b += B[1][0];
	for (int i=0;i<a.length();i++) if (a[i] == 'X') a.erase(a.begin()+i);
	for (int i=0;i<b.length();i++) if (b[i] == 'X') b.erase(b.begin()+i);

	for (int i=0;i<3;i++){
		a += a[0];
		a.erase(a.begin());
		if (a == b){
			puts("YES");
			return 0;
		}
	}
	puts("NO");
	return 0;
}