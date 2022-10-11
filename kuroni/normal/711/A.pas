var n, ans, i: integer;
    A: array[1..1000] of ansistring;
    tmp : ansistring;
    chk: boolean;
begin
  readln(n);
  for i := 1 to n do readln(A[i]);
  chk := false;
  for i := 1 to n do
  begin
    tmp := A[i];
    if (tmp[1] = 'O') and (tmp[2] = 'O') then
    begin
      tmp[1] := '+';
      tmp[2] := '+';
      chk := true;
      A[i] := tmp;
      break;
    end;
    if (tmp[4] = 'O') and (tmp[5] = 'O') then
    begin
      tmp[4] := '+';
      tmp[5] := '+';
      chk := true;
      A[i] := tmp;
      break;
    end;
  end;
  if not(chk) then write('NO') else
  begin
    writeln('YES');
    for i := 1 to n do writeln(A[i]);
  end;
end.