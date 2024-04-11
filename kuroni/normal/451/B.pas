var i, j, n, k: longint;
    A: array[1..100000] of longint;
function sorted(i, j: longint): boolean;
begin
  for k := i to j - 1 do if A[k] >= A[k+1] then exit(false);
  exit(true);
end;
begin
  read(n);
  for i := 1 to n do read(A[i]);
  for k := 1 to n do begin i := k; if A[k] >= A[k+1] then break; end;
  for k := i to n do begin j := k; if A[k] <= A[k+1] then break; end;
  if ((sorted(1,i-1)) and (sorted(j+1,n)) and (A[j] > A[i-1]) and ((A[i] < A[j+1]) or (j = n)))
  then
  begin
    writeln('yes');
    write(i,' ',j);
  end
  else write('no');
end.