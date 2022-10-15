import atexit
import io
import sys

_INPUT_LINES = sys.stdin.read().splitlines()
input = iter(_INPUT_LINES).__next__
_OUTPUT_BUFFER = io.StringIO()
sys.stdout = _OUTPUT_BUFFER


@atexit.register
def write():
    sys.__stdout__.write(_OUTPUT_BUFFER.getvalue())



n, m, k = map(int, input().split())
row = [(0, 0)]*n
col = [(0, 0)]*m

for i in range(k):
    t, rc, a = map(int, input().split())
    rc -= 1
    if t == 1:
        row[rc] = (i, a)
    else:
        col[rc] = (i, a)

for i in range(n):
    for j in range(m):
        upd = max(row[i], col[j])
        if upd == (0, 0):
            print(0,end=' ')
        else:
            print(upd[1],end=' ')
    print( )