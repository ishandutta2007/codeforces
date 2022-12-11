program project1;

const type1 : array[1..5] of string  = ('0','127','32767','2147483647','9223372036854775807');
      typen : array[2..5] of string = ('byte','short','int','long');

var
   st : string;
   i : longint;
begin
     readln(st);
     for i:=2 to 5 do begin
         if ((length(st) < length(type1[i])) or ((length(st) = length(type1[i])) and (st <= type1[i]))) and ((length(st) > length(type1[i - 1])) or ((length(st) = length(type1[i - 1])) and (st > type1[i - 1]))) then begin
            writeln(typen[i]);
            halt;
         end;
     end;
     writeln('BigInteger')
end.