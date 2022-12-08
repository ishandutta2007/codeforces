#include <stdio.h>

int coeff[4][3] = {{1,1,1},{1,1,-1},{1,-1,1},{1,-1,-1}};
long long min[4],max[4];

int N; long long x[3][100100];

long long X,Y,Z,D;
long long abs(long long a)
{
	return a < 0 ? -a : a;
}

void upd(long long p, long long q, long long r)
{
	long long d = 0;
	for (int i=0;i<N;i++){
		long long s = abs(p-x[0][i]) + abs(q-x[1][i]) + abs(r-x[2][i]);
		if (d < s)
			d = s;
	}
	if (d < D){
		X = p; Y = q; Z = r;
		D = d;
	}
}

bool chk(long long m)
{
	for (int i=0;i<N;i++){
		for (int k=0;k<4;k++){
			long long sum = 0;
			for (int j=0;j<3;j++) sum += coeff[k][j] * x[j][i];
			if (i == 0){
				min[k] = sum - m;
				max[k] = sum + m;
			}
			else{
				if (min[k] < sum - m) min[k] = sum - m;
				if (max[k] > sum + m) max[k] = sum + m;
			}
		}
	}

	for (int k=0;k<4;k++) if (min[k] > max[k]) return 0;
	if (max[1] + max[2] < min[0] + min[3]) return 0;
	if (min[1] + min[2] > max[0] + max[3]) return 0;
	if (max[0] + max[3] < min[1] + min[2]) return 0;
	if (min[0] + min[3] > max[1] + max[2]) return 0;
	return 1;
}

int main()
{
	int T; scanf ("%d",&T); while (T--){
		scanf ("%d",&N);
		for (int i=0;i<N;i++){
			scanf ("%lld %lld %lld",&x[0][i],&x[1][i],&x[2][i]);
		}

		long long l=0,r=3.5e18,a;
		while (l <= r){
			long long m = (l + r) / 2;
			if (chk(m)){
				r = m - 1;
				a = m;
			}
			else{
				l = m + 1;
			}
		}
		chk(a);

		long long real[4];
		D = 9e18;
		for (int bias=0;bias<256;bias++){
			int t = bias / 16; bool good = 1;
			int u = bias % 16;
			for (int k=0;k<4;k++){
				if(t & 1){
					real[k] = max[k];
					if (u & (1<<k)) real[k]--;
				}
				else{
					real[k] = min[k];
					if (u & (1<<k)) real[k]++;
				}
				if (real[k] < min[k] || real[k] > max[k]) good = 0;
				t /= 2;
			}

			//int coeff[4][3] = {{1,1,1},{1,1,-1},{1,-1,1},{1,-1,-1}};
			if (good){
				if ((real[0] - real[1]) % 2 == 0 && (real[0] - real[2]) % 2 == 0){
					long long r = (real[0] - real[1]) / 2;
					long long q = (real[0] - real[2]) / 2;
					long long p = real[0] - r - q;
					upd(p,q,r);
				}
				if ((real[0] - real[1]) % 2 == 0 && (real[0] + real[3]) % 2 == 0){
					long long r = (real[0] - real[1]) / 2;
					long long p = (real[0] + real[3]) / 2;
					long long q = real[0] - r - p;
					upd(p,q,r);
				}
				if ((real[0] - real[2]) % 2 == 0 && (real[0] + real[3]) % 2 == 0){
					long long q = (real[0] - real[2]) / 2;
					long long p = (real[0] + real[3]) / 2;
					long long r = real[0] - q - p;
					upd(p,q,r);
				}
				if ((real[1] + real[2]) % 2 == 0 && (real[1] - real[3]) % 2 == 0){
					long long p = (real[1] + real[2]) / 2;
					long long q = (real[1] - real[3]) / 2;
					long long r = real[2] + q - p;
					upd(p,q,r);
				}
			}
		}
		printf ("%lld %lld %lld\n",X,Y,Z);
	}

	return 0;
}