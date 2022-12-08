#include <stdio.h>
#include <string>
#include <complex>
#include <vector>
using namespace std;
typedef vector<int> VI;
typedef complex<double> C;
typedef vector<C> VC;
const double pi = 3.1415926535897932384626433832795;// acos(-1.)

int rev(int a, int u)
{
    int r = 0;
    u--;
    while (u){
        r <<= 1;
        r += a & 1;
        a >>= 1;
        u >>= 1;
    }
    return r;
}

C I[1<<19],M[1<<19],T[1<<19],W[1<<19]; int Z;
int R[1<<19];

void FFT(int inv)
{
    int i,h,j,k;

    for (i=0;i<Z;i++) T[R[i]] = I[i];
    for (i=2,h=1;i<=Z;i*=2,h*=2){
        for (k=0;k<Z;k+=i){
            for (j=0;j<h;j++){
                C w = W[Z/i*j];
                if (inv) w = conj(w);
                C t = w * T[k+j+h];
                C u = T[k+j];
                T[k+j] = u + t;
                T[k+j+h] = u - t;
            }
        }
    }

    if (inv) for (i=0;i<Z;i++) T[i] /= Z;
}

VI multi(VI& A, VI& B)
{
    int L = -1 + A.size() + B.size(),i; 
    for (Z=1;Z<=L;Z*=2);
    for (i=0;i<Z;i++){
        R[i] = rev(i,Z);
        W[i] = polar(1.,2*pi*i/Z);
    }

    for (i=0;i<A.size();i++) I[i] = A[i];
    for (i=A.size();i<Z;i++) I[i] = 0;
    FFT(0);
    for (i=0;i<Z;i++) M[i] = T[i];

    for (i=0;i<B.size();i++) I[i] = B[i];
    for (i=B.size();i<Z;i++) I[i] = 0;
    FFT(0);

    for (i=0;i<Z;i++) I[i] = T[i] * M[i];
    FFT(1);
    
    VI C(Z);
    for (i=0;i<Z;i++) C[i] = floor(T[i].real()+0.3);

    return C;
}

int sl, tl, k;
char S[200002],F[200002];
int cnt[200002],ans[1<<19];

int main()
{
    scanf ("%d %d %d",&sl,&tl,&k);
    scanf ("%s %s",S,F);

    string s = "AGCT";
    for (char c : s){
        for (int i=0;i<sl;i++) cnt[i] = 0;
        for (int i=0;i<sl;i++) if (S[i] == c){
            int l = i - k, r = i + k + 1;
            if (l < 0) l = 0;
            cnt[l]++;
            if (r < sl) cnt[r]--;
        }
        VI A;
        for (int i=0;i<sl;i++){
            if (i) cnt[i] += cnt[i-1];
            if (cnt[i]) A.push_back(1);
            else A.push_back(0);
        }
        VI B;
        for (int i=tl-1;i>=0;i--){
            if (F[i] == c) B.push_back(1);
            else B.push_back(0);
        }
        VI C = multi(A,B);
        for (int i=0;i<C.size();i++) ans[i] += C[i];
    }

    int res = 0;
    for (int i=0;i<(1<<19);i++) if (ans[i] == tl) res++;
    printf ("%d\n",res);

    return 0;
}