//QwQcOrZ yyds!!!
#ifndef _GLIBCXX_NO_ASSERT
#include <cassert>
#endif
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <cmath>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>

#if __cplusplus >= 201103L
#include <ccomplex>
#include <cfenv>
#include <cinttypes>
#include <cstdalign>
#include <cstdbool>
#include <cstdint>
#include <ctgmath>
#include <cwchar>
#include <cwctype>
#endif

// C++
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>

#if __cplusplus >= 201103L
#include <array>
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <initializer_list>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <thread>
#include <tuple>
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#endif
#define ll long long
#define F(i,a,b) for (int i=(a);i<=(b);i++)
#define R(i,a,b) for (int i=(a);i<(b);i++)
#define D(i,a,b) for (int i=(a);i>=(b);i--)
#define go(i,x) for (int i=head[x];i;i=e[i].nx)
#define mp make_pair
#define pb push_back
#define pa pair < int,int >
#define fi first
#define se second
#define re register
#define be begin()
#define en end()
#define sqr(x) ((x)*(x))
#define ret return puts("-1"),0;
#define put putchar('\n')
#define inf 1000000005
#define mod 998244353
//#define int ll
//#define N
#define maxn 100005
#define M 10005
#define LEFT 1
#define RIGHT 1
using namespace std;
 
typedef struct Node
{
    int key;
    struct Node *left;
    struct Node *right;
    int height;
}BTNode;
 
int max(int a, int b);
 
 
int height(struct Node *N)
{
    if (N == NULL)
        return 0;
    return N->height;
}
 
int max(int a, int b)
{
    return (a > b) ? a : b;
}
 
BTNode* newNode(int key)
{
    struct Node* node = (BTNode*)malloc(sizeof(struct Node));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return(node);
}
 
BTNode* ll_rotate(BTNode* y)
{
    BTNode *x = y->left;
    y->left = x->right;
    x->right = y;
 
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;
 
    return x;
}
 
BTNode* rr_rotate(BTNode* y)
{
    BTNode *x = y->right;
    y->right = x->left;
    x->left = y;
 
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;
 
    return x;
}
 
int getBalance(BTNode* N)
{
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}
 
BTNode* insert(BTNode* node, int key)
{
 
    if (node == NULL)
        return newNode(key);
 
    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else
        return node;
 
    node->height = 1 + max(height(node->left), height(node->right));
 
 
    int balance = getBalance(node);
 
 
 
    if (balance > 1 && key < node->left->key) //LL
        return ll_rotate(node);
 
 
    if (balance < -1 && key > node->right->key)     //RR
        return rr_rotate(node);
 
 
    if (balance > 1 && key > node->left->key)     //LR
    {
        node->left = rr_rotate(node->left);
        return ll_rotate(node);
    }
 
    if (balance < -1 && key < node->right->key)     //RL
    {
        node->right = ll_rotate(node->right);
        return rr_rotate(node);
    }
 
    return node;
}
 
 
void preOrder(struct Node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->key);
        preOrder(root->left);
        preOrder(root->right);
    }
}
 
int work()
{
    BTNode *root = NULL;
 
    root = insert(root, 2);
    root = insert(root, 1);
    root = insert(root, 0);
    root = insert(root, 3);
    root = insert(root, 4);
    root = insert(root, 4);
    root = insert(root, 5);
    root = insert(root, 6);
    root = insert(root, 9);
    root = insert(root, 8);
    root = insert(root, 7);
 
    printf("");
    preOrder(root);
    return 0;
}
inline char gc(){static char buf[100000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int T, n, ans[3];
char a[305][305];
signed main()
{
    ios::sync_with_stdio(false);
    cin >> T;
    while (T--)
    {
        cin >> n;
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                cin >> a[i][j];
            }
        }
        for (int i = 0; i < 3; ++i)
        {
            ans[i] = 0;
            for (int j = 1; j <= n; ++j)
            {
                for (int k = 1; k <= n; ++k)
                {
                    if (a[j][k] == 'X' && (j + k) % 3 == i)
                    {
                        ++ans[i];
                    }
                }
            }
        }
        int res = min_element(ans, ans + 3) - ans;
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                if (a[i][j]=='X'&&(i+j) %3== res)
                    a[i][j]='O';
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                cout << a[i][j];
            }
            cout << endl;
        }
    }
    return 0;
}
/*

*/