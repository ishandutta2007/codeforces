var n, i:longint;
    str: ansistring;

function Left(n: longint): boolean;
begin
  for i := 1 to n do if ((str[i] = '1') or ((str[i] = '4') or ((str[i] = '7') or (str[i] = '0')))) then exit(false);
  exit(true);
end;
function Right(n: longint): boolean;
begin
  for i := 1 to n do if ((str[i] = '3') or ((str[i] = '6') or ((str[i] = '9') or (str[i] = '0')))) then exit(false);
  exit(true);
end;
function Up(n: longint): boolean;
begin
  for i := 1 to n do if ((str[i] = '1') or ((str[i] = '2') or ((str[i] = '3')))) then exit(false);
  exit(true);
end;
function Down(n: longint): boolean;
begin
  for i := 1 to n do if ((str[i] = '7') or ((str[i] = '0') or ((str[i] = '9')))) then exit(false);
  exit(true);
end;
begin
  readln(n);
  read(str);
  if (Left(n) or (Right(n) or (Up(n) or Down(n)))) then write('NO') else write('YES');
end.