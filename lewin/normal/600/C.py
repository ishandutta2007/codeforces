import sys
import collections
from string import ascii_lowercase

f = sys.stdin

s = f.readline().rstrip("\n")

letters = collections.Counter(s)
odd = sorted([m for m,c in letters.items() if c % 2 == 1])
for m in odd[len(odd)/2:]: letters[m] -= 1
for m in odd[:len(odd)/2]: letters[m] += 1
middle = "" if len(odd) % 2 == 0 else odd[len(odd)/2]

ret = ""
for m in ascii_lowercase:
    ret += m * (letters[m]/2)

print ret + middle + ret[::-1]