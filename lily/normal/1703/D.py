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
    
    
T = int(input())
while T > 0:
    T -= 1
    n = int(input())
    s = set()
    a = []
    for i in range(n):
        a.append(input())
        s.add(a[-1])
    for i in a:
        ans = 0
        for j in range(len(i) - 1):
            if i[:j + 1] in s and i[j + 1:] in s:
                ans = 1
        print(ans, end="")
    print()