Program ziola;
Var
i, n, l, r, answer: longint;
A, B, jest1, jest2: array[1..100000] of LongInt;

Begin
Readln(n, l, r);
for i := 1 to n do read(A[i]);
readln;
for i := 1 to n do read(B[i]);
answer := 1;

for i := 1 to l-1 do
if (A[i] <> B[i]) then answer := 0;

for i := l to r do 
begin
	inc(jest1[A[i]]);
	inc(jest2[B[i]]);
end;

for i := 1 to n do
	if (jest1[i] <> jest2[i]) then answer := 0;
	
for i := r+1 to n do
if (A[i] <> B[i]) then answer := 0;

if (answer = 0) then writeln('LIE')
else writeln('TRUTH')

End.