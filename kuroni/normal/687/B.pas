var n, i: longint;
    k, check, c: qword;

function GCD(a, b: qword): qword;
var temp: qword;
    begin
      while b <> 0 do
      begin
        temp := b;
        b := a mod b;
        a := temp
       end;
      result := a
    end;

begin
  read(n,k);
  check := 1;
  for i := 1 to n do
  begin
    read(c);
    check := check*c div (GCD(check,c));
    check := GCD(k,check);
    if check = k then break;
  end;
  if check = k then write('Yes') else write('No');
end.