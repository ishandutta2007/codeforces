#include <cstdio>
#include <cstring>
#include <xmmintrin.h>
#include <emmintrin.h>
#include <intrin.h>

using namespace std;

typedef unsigned int uint;

const int N = 1 << 18;
const int B = 128;

__declspec( align( 16 ) ) int s0[B][N / 32];
__declspec( align( 16 ) ) int s1[B][N / 32];


int get_bit(int* st, uint offset) {
    return (st[offset >> 5] & (1 << (offset & 31))) ? 1 : 0;
}

void flip_bit(int* st, uint offset) {
    st[offset >> 5] ^= (1 << (offset & 31));
}

inline int calc(int* __restrict st1, uint offset1, int* __restrict st2, uint offset2) {
    offset1 >>= 5;
    offset2 >>= 5;
    st1 += offset1;
    st2 += offset2;
    __m128i f = _mm_xor_si128(*reinterpret_cast<__m128i*>(st1), *reinterpret_cast<__m128i*>(st2));
    uint* ptr = reinterpret_cast<uint*>(&f);
    return __popcnt(*ptr) + __popcnt(*(ptr + 1)) + __popcnt(*(ptr + 2)) + __popcnt(*(ptr + 3));
}


char a[N];
char b[N];

int main() {
    gets(a);
    gets(b);
    int len_a = strlen(a);
    int len_b = strlen(b);
    for (int dx = 0; dx < 128; dx++) {
        for (int i = 0; i + dx < len_a; i++)
            if (a[i + dx] == '1')
                flip_bit(s0[dx], i);
        for (int i = 0; i + dx < len_b; i++)
            if (b[i + dx] == '1')
                flip_bit(s1[dx], i);
    }
    int q;
    scanf("%d", &q);
    for (int t = 0; t < q; t++) {
        int a, b, len;
        scanf("%d%d%d", &a, &b, &len);
        int dx1 = a % 128;
        int dx2 = b % 128;
        int i = 0;
        int res = 0;
        for (; i + 128 <= len; i += 128)
            res += calc(s0[dx1], a - dx1 + i, s1[dx2], b - dx2 + i);
        for (; i < len; i++)
            if (get_bit(s0[dx1], a - dx1 + i) != get_bit(s1[dx2], b - dx2 + i))
                res++;
        printf("%d\n", res);
    }
    return 0;
}