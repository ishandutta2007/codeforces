var str: string;
  i, j, m, n: longint;
  check: boolean;
begin
  check := false;
  readln(m,n);
  for i := 1 to m do
  begin
    readln(str);
    if ((pos('Y',str) > 0) or (pos('C',str) > 0) or (pos('M',str) > 0)) then check := true;
  end;
  if check then write('#Color') else write('#Black&White');
end.