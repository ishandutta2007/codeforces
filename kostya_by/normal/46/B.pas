program project1;

const
tshirt : array [1..5] of string = ('S','M','L','XL','XXL');

var
q : array[1..5] of integer;
ans: array[1..1010] of string;
i,j,k,a,h:longint;
st:string;
begin
     for i:=1 to 5 do read(q[i]);
     readln(k);
     for i:=1 to k do begin
         readln(st);
         for j:=1 to 5 do begin
             if st=tshirt[j] then break;
         end;
            h:=maxlongint;
            for a:=1 to 5 do begin
                if (q[a]<>0) and (abs(j-a)<=abs(j-h)) then h:=a;
            end;
            ans[i]:=tshirt[h];
            dec(q[h]);
     end;
     for i:=1 to k do begin
         writeln(ans[i]);
     end;
end.