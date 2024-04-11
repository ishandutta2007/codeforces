A, B, s = input(), input(), input()
print(s.translate(str.maketrans(A + A.upper(), B + B.upper())))