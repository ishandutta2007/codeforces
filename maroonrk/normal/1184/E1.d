import std.conv, std.functional, std.range, std.stdio, std.string;
import std.algorithm, std.array, std.bigint, std.complex, std.container, std.math, std.numeric, std.regex, std.typecons;
import core.bitop;

class EOFException : Throwable { this() { super("EOF"); } }
string[] tokens;
string readToken() { for (; tokens.empty; ) { if (stdin.eof) { throw new EOFException; } tokens = readln.split; } auto token = tokens.front; tokens.popFront; return token; }
int readInt() { return readToken.to!int; }
long readLong() { return readToken.to!long; }
real readReal() { return readToken.to!real; }

bool chmin(T)(ref T t, in T f) { if (t > f) { t = f; return true; } else { return false; } }
bool chmax(T)(ref T t, in T f) { if (t < f) { t = f; return true; } else { return false; } }

int binarySearch(alias pred, T)(in T[] as) { int lo = -1, hi = cast(int)(as.length); for (; lo + 1 < hi; ) { const mid = (lo + hi) >> 1; (unaryFun!pred(as[mid]) ? hi : lo) = mid; } return hi; }
int lowerBound(T)(in T[] as, T val) { return as.binarySearch!(a => (a >= val)); }
int upperBound(T)(in T[] as, T val) { return as.binarySearch!(a => (a > val)); }


int root(int[] uf, int u) {
  return (uf[u] < 0) ? u : (uf[u] = uf.root(uf[u]));
}
bool connect(int[] uf, int u, int v) {
  u = uf.root(u);
  v = uf.root(v);
  if (u == v) return false;
  if (uf[u] > uf[v]) swap(u, v);
  uf[u] += uf[v];
  uf[v] = u;
  return true;
}

int N, M;
int[] A, B;
long[] E;

void main() {
  try {
    for (; ; ) {
      N = readInt();
      M = readInt();
      A = new int[M];
      B = new int[M];
      E = new long[M];
      foreach (i; 0 .. M) {
        A[i] = readInt() - 1;
        B[i] = readInt() - 1;
        E[i] = readLong();
      }
      
      Tuple!(long, int)[] es;
      foreach (i; 1 .. M) {
        es ~= tuple(E[i], i);
      }
      es.sort;
      debug {
        writeln(es);
      }
      
      auto uf = new int[N];
      uf[] = -1;
      long ans;
      foreach (j; 0 .. M - 1) {
        if (uf.root(A[0]) != uf.root(B[0])) {
          ans = es[j][0];
        }
        const i = es[j][1];
        uf.connect(A[i], B[i]);
      }
      if (uf.root(A[0]) != uf.root(B[0])) {
        ans = 10L^^9;
      }
      writeln(ans);
    }
  } catch (EOFException e) {
  }
}