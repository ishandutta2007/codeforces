#include <stdio.h>

int A,B,F;
char P[22][22];

bool chk(int a, int b, int c, int d, int p, int q, int r, int s)
{
	int i,j,f;

	f = 0;
	for (i=a;i<=b;i++){
		for (j=c;j<=d;j++){
			if (P[i][j] != P[i-a+p][j-c+r]){f = 1; break;}
		} if(f) break;
	}
	if (f==0) return true;

	f = 0;
	for (i=a;i<=b;i++){
		for (j=c;j<=d;j++){
			if (P[i][j] != P[q+a-i][s+c-j]){f = 1; break;}
		} if(f) break;
	}
	if (f==0) return true;

	if (b - a == d - c){
		f = 0;
		for (i=a;i<=b;i++){
			for (j=c;j<=d;j++){
				if (P[i][j] != P[j-c+p][s+a-i]){f = 1; break;}
			} if(f) break;
		}
		if (f==0) return true;

		f = 0;
		for (i=a;i<=b;i++){
			for (j=c;j<=d;j++){
				if (P[i][j] != P[q+c-j][i-a+r]){f = 1; break;}
			} if(f) break;
		}
		if (f==0) return true;
	}

	return false;
}

int main()
{
	int i,j,k,l,o,p,a,b,c,m; c = 0; m = 0x7fffffff;

	scanf ("%d %d",&A,&B);

	for (i=0;i<A;i++) scanf ("%s",P[i]);
	for (i=1;i<=A;i++){
		if (A % i == 0){
			for (j=1;j<=B;j++){
				if (B % j == 0){
					F = 0;
					for (k=0;k<A/i;k++){
						for (l=0;l<B/j;l++){
							for (o=k;o<A/i;o++){
								for (p=0;p<B/j;p++){
									if (k == o && l == p) continue;
									if (chk(k*i,k*i+i-1,l*j,l*j+j-1,o*i,o*i+i-1,p*j,p*j+j-1)){F = 1; break;}
								}
								if(F) break;
							}
							if(F) break;
						}
						if(F) break;
					}

					if (F == 0){
						if (m > i * j){
							m = i * j; a = i; b = j;
						}
						c++;
					}
				}
			}
		}
	}

	printf ("%d\n%d %d",c,a,b);

	return 0;
}