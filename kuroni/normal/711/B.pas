var n, i, j, ansi, ansj: longint;
    sum, tmp: int64;
    A: array[1..500,1..500] of int64;
begin
  read(n);
  for i := 1 to n do for j := 1 to n do
  begin
    read(A[i,j]);
    if (A[i,j] = 0) then begin ansi := i; ansj := j; end;
  end;
  if n = 1 then begin write(1); halt; end;
  for j := 1 to n do inc(tmp,a[ansi - 1 + n*(ord(ansi - 1 = 0)), j]);
  sum := tmp;
  for j := 1 to n do dec(sum,a[ansi, j]);
  if (sum <= 0) then begin
    write(-1);
    halt;
  end;
  A[ansi, ansj] := sum;
  for i := 1 to n do
  begin
    sum := 0;
    for j := 1 to n do inc(sum, A[i,j]);
    if (sum <> tmp) then begin write(-1); halt; end;
  end;
  for j := 1 to n do
  begin
    sum := 0;
    for i := 1 to n do inc(sum, A[i,j]);
    if (sum <> tmp) then begin write(-1); halt; end;
  end;
  sum := 0;
  for i := 1 to n do inc(sum, A[i,i]);
  if (sum <> tmp) then begin write(-1); halt; end;
  sum := 0;
  for i := 1 to n do inc(sum, A[i,n-i+1]);
  if (sum <> tmp) then begin write(-1); halt; end;
  write(A[ansi, ansj]);
end.